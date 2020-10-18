#include <SFML/Graphics.hpp>
#include "Windows.h"
#include "GameManager.h"


void main()
{

	FreeConsole();

	GameManager gameManager;

	while (gameManager.isWindowRunning())
	{
		gameManager.update();

		gameManager.render();
	}
}