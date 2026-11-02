#include "Game.h"

using namespace std;

void Game::initialize() {
	cout << "Initialisation du jeu ...\n\n";
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

		im.Render();

		if (im.GetKey() == 'a') {
			hm.Get(0).Attack(em.Get(0));
		}

		em.Get(0).Attack(hm.Get(0));

		for (size_t i = 0; i < em.GetSize(); i++) {
			if (!em.Get(i).isAlive()) {
				isRunning = false;
			}
		}
		for (size_t i = 0; i < hm.GetSize(); i++) {
			if (!hm.Get(i).isAlive()) {
				isRunning = false;
			}
		}

	}
}

void Game::Shutdown() {
	cout << "Fermeture du jeu\n";
}