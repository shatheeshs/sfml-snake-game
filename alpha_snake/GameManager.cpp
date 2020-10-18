#include <iostream>
#include "GameManager.h"

GameManager::GameManager()
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
}

void GameManager::render()
{
	this->window->clear();

	//Do Render
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
	this->window->setFramerateLimit(60);
}

void GameManager::SetupEnv()
{
}
