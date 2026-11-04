#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	Game game;

	game.Menu();

	game.Loop();
	game.Shutdown();

	return 0;
}