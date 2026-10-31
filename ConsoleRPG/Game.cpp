#include "Game.h"

using namespace std;

void Game::initialize() {
	cout << "Initialisation du jeu ...\n";
	hm.Add(make_unique<Warrior>("Ronan"));
	hm.Add(make_unique<Mage>("Icien"));

	em.Add(make_unique<Goblin>("Goblin"));
}

void Game::loop() {
	isRunning = true;
	while (isRunning)
	{
		hm.UpdateAll();
		em.UpdateAll();

		hm.RenderAll();
		em.RenderAll();

		hm.Get(0).Attack(em.Get(0));

		if (!em.Get(0).isAlive()) {
			isRunning = false;
		}
	}
}

void Game::Shutdown() {
	cout << "Fermeture du jeu\n";
}