#include <SFML/Graphics.hpp>
#include "Windows.h"
#include "GameManager.h"


int main()
{

	//GameManager
	GameManager gameManager;

	while (gameManager.isWindowRunning())
	{
		gameManager.update();

		gameManager.render();
	}

	return 0;
}