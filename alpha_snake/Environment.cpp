#include "Environment.h"

Environment::Environment()
{
}

Environment::Environment(sf::Vector2u windSize)
{
	blockSize = 16;
	windowSize = windSize;
	respawnApple();
	appleShape.setFillColor(sf::Color::Red);
	appleShape.setRadius(blockSize / 2);
	for (int i = 0; i < 4; ++i) {
		bounds[i].setFillColor(sf::Color(150, 0, 0));
		if (!((i + 1) % 2)) {
			bounds[i].setSize(sf::Vector2f(windowSize.x,
				blockSize));
		}
		else {
			bounds[i].setSize(sf::Vector2f(blockSize,
				windowSize.y));
		}
		if (i < 2) {
			bounds[i].setPosition(0, 0);
		}
		else {
			bounds[i].setOrigin(bounds[i].getSize());
			bounds[i].setPosition(sf::Vector2f(windowSize));
		}
	}
}

Environment::~Environment()
{
}

int Environment::getBlockSize()
{
	return blockSize;
}

void Environment::respawnApple()
{
	int maxX = (windowSize.x / blockSize) - 2;
	int maxY = (windowSize.y / blockSize) - 2;
	item = sf::Vector2i(
		rand() % maxX + 1, rand() % maxY + 1);
	appleShape.setPosition(
		item.x * blockSize,
		item.y * blockSize);
}

void Environment::updateEnviroment(Snake& player)
{
	if (player.getPosition() == item) {
		player.extend();
		player.increaseScore();
		respawnApple();
	}
	int gridSize_x = windowSize.x / blockSize;
	int gridSize_y = windowSize.y / blockSize;
	if (player.getPosition().x <= 0 ||
		player.getPosition().y <= 0 ||
		player.getPosition().x >= (gridSize_x - 1) ||
		player.getPosition().y >= (gridSize_y - 1))
	{
		player.setLose();
	}
}

void Environment::renderEnvironment(sf::RenderWindow& window)
{
	for (int i = 0; i < 4; ++i) {
		window.draw(bounds[i]);
	}
	window.draw(appleShape);
}
