#include <SFML/Graphics.hpp>
#include "Windows.h"
#include "GameManager.h"


void main()
{

	//GameManager
	GameManager gameManager;

	while (gameManager.isWindowRunning())
	{
		gameManager.update();

		gameManager.render();
	}
}