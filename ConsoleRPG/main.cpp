#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	Game game;
	game.initialize();
	game.loop();
	game.Shutdown();

	return 0;
}