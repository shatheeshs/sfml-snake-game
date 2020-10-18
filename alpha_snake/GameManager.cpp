#include <iostream>
#include <exception>
#include "GameManager.h"
#include <windows.h>

GameManager::GameManager() :env(sf::Vector2u(800, 600)) , snake(env.getBlockSize()), timeElapsed(100000)
{
	this->Init();
}

GameManager::~GameManager()
{
	delete this->window;
}

void GameManager::update()
{
	//Event Polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		default:
			break;
		}
	}

	//Do update
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
		&& snake.getDirection() != Direction::Down)
	{
		snake.setDirection(Direction::Up);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
		&& snake.getDirection() != Direction::Up)
	{
		snake.setDirection(Direction::Down);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
		&& snake.getDirection() != Direction::Right)
	{
		snake.setDirection(Direction::Left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
		&& snake.getDirection() != Direction::Left)
	{
		snake.setDirection(Direction::Right);
	}


	float timestep = 10.0f / snake.getSpeed();
	if (timeElapsed >= timestep) {
		snake.tick();
		env.updateEnviroment(snake);
		timeElapsed -= timestep;
		if (snake.hasLost()) {
			snake.reset();
		}
	}

}

void GameManager::render()
{
	this->window->clear();

	//Do Render
	env.renderEnvironment(*window);
	snake.renderSnake(*window);

	this->window->display();
}

const bool GameManager::isWindowRunning()
{
	return this->window->isOpen();
}

void GameManager::updateWindowMousePos()
{
}

void GameManager::Init()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "SNAKE XENXIA", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(10);

	try
	{
		icon.loadFromFile("Resources\\snake-icon.png");
		//Set Icon to Title Bar
		this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	}
	catch (std::exception& e)
	{
		MessageBox(NULL, "Error", e.what(), MB_OK);
	}
}

void GameManager::SetupEnv()
{
}
