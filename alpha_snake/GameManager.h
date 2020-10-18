#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Environment.h"
#include "Snake.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	sf::RenderWindow* window;
	sf::Event ev;

	void update();
	void render();
	const bool isWindowRunning();
	void updateWindowMousePos();

private:
	void Init();
	void SetupEnv();

	int timeElapsed;
	Environment env;
	Snake snake;

};
