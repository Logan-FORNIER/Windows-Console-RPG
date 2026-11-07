#pragma once
#include "Game.h"

using namespace std;

void Game::Update() {
	switch (state)
	{
	case GameState::Menu:
		Menu();
		break;
	case GameState::Exploration:
		UpdateLocation();
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
	char KeyPlayed = im.GetKey();

	int nbEnnemis = static_cast<int>(em.GetSize());

	if (KeyPlayed == 'a') {
		cout << "Lequel attaquer ? (Entre un numero entre 0 et " << nbEnnemis - 1 << ")\n";

		int targetIndex = im.NumberSecurity(0, nbEnnemis - 1);

		if (targetIndex >= 0 && targetIndex < nbEnnemis && em.Get(targetIndex).isAlive()) {

			hm.Get(0).Attack(em.Get(targetIndex));

			for (int i = 0; i < nbEnnemis; i++) {
				if (em.Get(i).isAlive()) {
					em.Get(i).Attack(hm.Get(0));
				}
			}
		}
		else {
			cout << "Cible invalide ou deja morte !\n";
		}
		system("pause");
	}

	if (KeyPlayed == 'f') {
		cout << hm.Get(0).GetName() << " a fui le combat !\n";
		system("pause");
		em.RemoveEnnemies();
		state = GameState::Exploration;
	}

	if (KeyPlayed == 'd') {
		hm.Get(0).Block();
		for (int i = 0; i < nbEnnemis; i++) {
			if (em.Get(i).isAlive()) {
				em.Get(i).Attack(hm.Get(0));
			}
		}
		system("pause");
	}
}

void Game::GenerateRandomEvent() {
	int pourcent = rand() % 100;
	int luck = rand() % 2;

	if (pourcent < 10) {
		cout << "Bienvenue dans les montages\n";

		if (luck == 1) {
			cout << "Un Orc vous attaque !\n";
			em.RemoveEnnemies();
			em.Add(make_unique<Orc>("Orc Sauvage"));

			isBossFight = false;
			state = GameState::Combat;
		}
		else {
			cout << "Rien ne se passe.\n";
		}
	}
	else if (pourcent < 40) {
		cout << "Bienvenue dans les plaines sauvages\n";

		if (luck == 1) {

			int RandEnnemies = (rand() % 3) + 1;

			cout << "Un groupe de " << RandEnnemies << " gobelins vous attaque !\n";
			em.RemoveEnnemies();

			for (int i = 0; i < RandEnnemies; i++) {
				em.Add(make_unique<Goblin>("Goblin Sauvage"));
			}

			isBossFight = false;
			state = GameState::Combat;
		}
		else {
			cout << "Rien ne se passe.\n";
		}
	}
	else if (pourcent < 70) {
		cout << "Bienvenue dans le village\n";

		if (luck == 1)
		{
			cout << "Un villageois vous intercepte et vous demande si vous voulez vous entrainer avec lui.\n";
			cout << "Voulez-vous accepter l'entrainement ? (1: Oui, 2: Non)\n";

			int choixEntrainement = im.NumberSecurity(1, 2);

			if (choixEntrainement == 1) {
				cout << "\nVous passez du temps a vous entrainer intensement...\n";
				hm.Get(0).Train((rand() % 37));
			}
			else {
				cout << "\nVous refusez poliment et continuez votre chemin.\n";
			}
		}
		else {
			cout << "Rien ne se passe.\n";
		}
	}
	else if (pourcent < 75) {
		cout << "Bienvenue dans le Temple Ancien\n";
		cout << "Vous croisez au loin une silhouette etrange... C'est un Empereur Orc !\n";

		em.RemoveEnnemies();
		em.Add(make_unique<EmperorOrc>("Empereur Orc"));

		isBossFight = true;
		state = GameState::Combat;
	}
	else {
		cout << "Vous etes dans un chemin abandonne.\n";
	}
	system("pause");
}

void Game::UpdateLocation() {
	cout << "Quelle direction voulez-vous prendre ? z: haut, s: bas, d: droite, q: gauche\n";

	char choice = im.GetKey();

	if (choice == 'z' || choice == 'q' || choice == 's' || choice == 'd') {
		GenerateRandomEvent();
	}
}

void Game::UpdateQuit() {
	cout << "r: Recommencer, q: Quitter\n";
	char PlayedKey = im.GetKey();

	if (PlayedKey == 'r') {
		Initialize();
	}
	else if (PlayedKey == 'q') {
		cout << "Fermeture du jeu\n";
		isRunning = false;
	}
	else {
		Menu();
	}
}

void Game::UpdateVictory() {
	int nbEnnemis = static_cast<int>(em.GetSize());
	bool allEnemiesDead = true;

	for (int i = 0; i < nbEnnemis; i++) {
		if (em.Get(i).isAlive()) {
			allEnemiesDead = false;
			break;
		}
	}

	if (allEnemiesDead && nbEnnemis > 0) {
		if (isBossFight) {
			cout << "Vous avez vaincu l'Empereur Orc et sauve le royaume !\n";
			em.RemoveEnnemies();
			system("pause");
			UpdateQuit();
		}
		else {
			cout << "\nVous avez repousse les gobelins avec succes ! Vous reprenez la route.\n";

			int xpGagnee = nbEnnemis * 30;
			hm.Get(0).Train(xpGagnee);

			em.RemoveEnnemies();
			system("pause");
			state = GameState::Exploration;
		}
	}
}

void Game::UpdateDefeat() {
	int nbHeroes = static_cast<int>(hm.GetSize());

	for (int i = 0; i < nbHeroes; i++) {
		if (!hm.Get(i).isAlive()) {
			cout << "\nMalheureusement vous vous etes fait vaincre...\n";
			em.RemoveEnnemies();
			system("pause");
			UpdateQuit();
			return;
		}
	}
}

void Game::CreditMenu() {
	std::cout << "========================================================================" << std::endl;
	std::cout << "                          CREDITS DU PROJET                             " << std::endl;
	std::cout << "========================================================================" << std::endl;
	std::cout << "                                                                        " << std::endl;
	std::cout << "   ______    _             _____   _  __     ____                       " << std::endl;
	std::cout << "  |  ____|  | |           |_   _| | |/ /   |  __  |                     " << std::endl;
	std::cout << "  | |__     | |             | |   | ' /    | |  | |                     " << std::endl;
	std::cout << "  |  __|    | |             | |   |  <|    | |  | |                     " << std::endl;
	std::cout << "  | |____   | |____   __   _| |_  | ._ \\   | |__| |                     " << std::endl;
	std::cout << "  |______|  |______| |__| |_____| |_| \\_\\  | ____ |                     " << std::endl;
	std::cout << "                                                                        " << std::endl;
	std::cout << "========================================================================" << std::endl;
	std::cout << "                     Developpe par EL_IKO                               " << std::endl;
	std::cout << "========================================================================" << std::endl;
	system("pause");
}

void Game::Menu() {
	cout << "[ Menu ]\n";
	cout << "P: Jouer, Q: Quitter, C: Credits\n";
	char MenuChoice = im.GetKey();

	switch (MenuChoice)
	{
	case 'p':
		cout << "Initialisation du jeu ...\n\n";
		Initialize();
		break;
	case 'q':
		cout << "Fermeture du jeu\n";
		isRunning = false;
		break;
	case 'c':
		CreditMenu();
		break;
	}
}

void Game::Initialize() {
	srand(static_cast<unsigned int>(time(NULL)));
	em.RemoveEnnemies();
	hm.RemoveHero();
	cout << "Selection de la classe : 1: Warrior, 2: Mage, 3: Necromancien\n";
	int Role = im.NumberSecurity(1, 3);

	if (Role == 1) {
		hm.Add(make_unique<Warrior>(im.GetNickname()));
	}
	else if (Role == 2) {
		hm.Add(make_unique<Mage>(im.GetNickname()));
	}
	else if (Role == 3) {
		hm.Add(make_unique<Necromancer>(im.GetNickname()));
	}

	state = GameState::Exploration;
	Loop();
}

void Game::Loop() {
	isRunning = true;
	while (isRunning)
	{
		system("cls");

		if (state == GameState::Exploration || state == GameState::Combat) {
			hm.RenderAll();
			em.RenderAll();

			if (state == GameState::Combat) {
				im.Render();
			}
		}

		Update();

		if (state == GameState::Combat) {
			UpdateVictory();
			UpdateDefeat();
		}
	}
}
