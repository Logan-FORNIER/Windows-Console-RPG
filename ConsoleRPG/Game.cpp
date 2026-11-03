#include "Game.h"

using namespace std;

void Game::initialize() {
	cout << "Initialisation du jeu ...\n\n";

	//hm.Add(make_unique<Warrior>("Ronan"));
	//hm.Add(make_unique<Mage>("Icien"));

	if (im.GetRole() == 1) {
		hm.Add(make_unique<Warrior>(im.GetNickname()));
	}
	else if (im.GetRole() == 2) {
		hm.Add(make_unique<Mage>(im.GetNickname()));
	}
	else {
		
	}

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

		char KeyPlayed = im.GetKey();

		if (KeyPlayed == 'a') {
			hm.Get(0).Attack(em.Get(0));
			em.Get(0).Attack(hm.Get(0));
		}

		if (KeyPlayed == 'f') {
			cout << hm.Get(0).GetName() << " a fui le " << em.Get(0).GetName() << endl;
			isRunning = false;
		}

		if (KeyPlayed == 'd') {
			hm.Get(0).Block(em.Get(0));
			em.Get(0).Attack(hm.Get(0));
		}

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