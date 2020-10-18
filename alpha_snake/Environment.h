#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Snake.h"

class Environment {
public:
	Environment();
	Environment(sf::Vector2u windSize);
	~Environment();
	int getBlockSize();
	void respawnApple();
	void updateEnviroment(Snake& player);
	void renderEnvironment(sf::RenderWindow& window);
private:
	sf::Vector2u windowSize;
	sf::Vector2i item;
	int blockSize;
	sf::CircleShape appleShape;
	sf::RectangleShape bounds[4];
};