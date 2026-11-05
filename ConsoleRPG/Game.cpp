#include "Game.h"

using namespace std;

void Game::Update() {
	switch (state)
	{
	case GameState::Menu:
		Menu();
		break;
	case GameState::Combat:
		UpdateCombat();
		break;
	case GameState::Victory:
		UpdateVictory();
		break;
	case GameState::Defeat:
		UpdateDefeat();
		break;
	case GameState::Quit:
		UpdateQuit();
		break;
	}
}

void Game::UpdateCombat() {
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
}

void Game::UpdateQuit() {
	cout << "r: Ressayer, q: Quit\n";
	char PlayedKey = im.GetKey();

	if (PlayedKey == 'r') {
		Initialize();
	}
	else if (PlayedKey == 'q') {
		cout << "Fermeture du jeu\n";
	}
	else {
		Menu();
	}
}

void Game::UpdateVictory() {
	for (size_t i = 0; i < em.GetSize(); i++) {
		if (!em.Get(i).isAlive()) {
			cout << "Felicitation vous avez vaincu la horde de goblin !\n";
			isRunning = false;
			UpdateQuit();
		}
	}
}

void Game::UpdateDefeat() {
	for (size_t i = 0; i < hm.GetSize(); i++) {
		if (!hm.Get(i).isAlive()) {
			cout << "Malheuresement vous vous etes fait capturer par la horde de Goblin\n";
			isRunning = false;
			UpdateQuit();
		}
	}
}

void Game::CreditMenu() {
	cout << "Dev : EL_IKO\n";
}

void Game::Menu() {
	cout << "[ Menu ]\n";
	cout << "P: play, Q: Quit, C: Credit\n";
	char MenuChoice = im.GetKey();

	switch (MenuChoice)
	{
	case 'p':
		cout << "Initialisation du jeu ...\n\n";
		Initialize();
		break;
	case 'q':
		cout << "Fermeture du jeu\n";
		break;
	case 'c':
		CreditMenu();
		break;
	}
}

void Game::Initialize() {
	cout << "Selection de la class : 1: Warrior, 2: Mage\n";
	int Role = im.NumberSecurity(1, 2);

	if (Role == 1) {
		hm.Add(make_unique<Warrior>(im.GetNickname()));
	}
	else if (Role == 2) {
		hm.Add(make_unique<Mage>(im.GetNickname()));
	}

	em.Add(make_unique<Goblin>("Goblin"));

	state = GameState::Combat;
	Loop();
}

void Game::Loop() {
	isRunning = true;
	while (isRunning)
	{
		hm.RenderAll();
		em.RenderAll();

		UpdateCombat();

		UpdateVictory();
		UpdateDefeat();
	}
}