#pragma once
#include "Game.h"

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
		std::cout << "Lequel attaquer ? (Entre un numero entre 0 et " << nbEnnemis - 1 << ")\n";

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
			std::cout << "Cible invalide ou deja morte !\n";
		}
		system("pause");
	}

	if (KeyPlayed == 'f') {
		std::cout << hm.Get(0).GetName() << GREEN << " a fui le combat !\n" << DEFAULT;
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
	int luck = rand() % 3;

	if (pourcent < 10) {
		std::cout << "Bienvenue dans les montages\n";

		if (luck == 1) {
			std::cout << RED << "Un Orc vous attaque !\n" << DEFAULT;
			em.RemoveEnnemies();
			em.Add(std::make_unique<Orc>("Orc Sauvage"));

			isBossFight = false;
			state = GameState::Combat;
		}
		else {
			std::cout << "Rien ne se passe.\n";
		}
	}
	else if (pourcent < 40) {
		std::cout << "Bienvenue dans les plaines sauvages\n";

		if (luck == 1) {

			int RandEnnemies = (rand() % 3) + 1;

			std::cout << RED << "Un groupe de " << RandEnnemies << " gobelins vous attaque !\n" << DEFAULT;
			em.RemoveEnnemies();

			for (int i = 0; i < RandEnnemies; i++) {
				em.Add(std::make_unique<Goblin>("Goblin Sauvage"));
			}

			isBossFight = false;
			state = GameState::Combat;
		}
		else {
			std::cout << "Rien ne se passe.\n";
		}
	}
	else if (pourcent < 70) {
		std::cout << "Bienvenue dans le village\n";

		if (luck == 1)
		{
			std::cout << YELLOW <<"Un villageois vous intercepte et vous demande si vous voulez vous entrainer avec lui.\n" << DEFAULT;
			std::cout << "Voulez-vous accepter l'entrainement ? (1: Oui, 2: Non)\n";

			int choixEntrainement = im.NumberSecurity(1, 2);

			if (choixEntrainement == 1) {
				std::cout << "\nVous passez du temps a vous entrainer intensement...\n";
				hm.Get(0).Train((rand() % 37));
			}
			else {
				std::cout << "\nVous refusez poliment et continuez votre chemin.\n";
			}
		}
		else if (luck == 2) {
			std::cout << YELLOW << "Un mage curatif vous demande si vous voulez etre soigne pour 8 piece de cuivre !\n" << DEFAULT;
			std::cout << "Acceptez vous ? (1: Oui, 2: Non)\n";

			int choixSoins = im.NumberSecurity(1, 2);

			if (choixSoins == 1) {
				if (hm.Get(0).GetMoney() >= 8) {
					int heal = (rand() % 30) + 1;
					std::cout << "\nLe mage vous soigne de " << heal << " PV\n";
					hm.Get(0).Purchase(8);
					hm.Get(0).TakeHeal(heal);
				}
				else {
					std::cout << "\nVous n'avez pas assez d'argent le mage s'en va\n";
				}
			}
			else {
				std::cout << "\nVous refusez poliment et continuez votre chemin.\n";
			}
		}
		else {
			std::cout << "Rien ne se passe.\n";
		}
	}
	else if (pourcent < 75) {
		std::cout << "Bienvenue dans le Temple Ancien\n";
		std::cout << RED << "Vous croisez au loin une silhouette etrange... C'est un Empereur Orc !\n" << DEFAULT;

		em.RemoveEnnemies();
		em.Add(std::make_unique<EmperorOrc>("Empereur Orc"));

		isBossFight = true;
		state = GameState::Combat;
	}
	else {
		std::cout << "Vous etes dans un chemin abandonne.\n";
	}
	system("pause");
}

void Game::UpdateLocation() {
	std::cout << "Quelle direction voulez-vous prendre ? z: haut, s: bas, d: droite, q: gauche\n";

	char choice = im.GetKey();

	if (choice == 'z' || choice == 'q' || choice == 's' || choice == 'd') {
		GenerateRandomEvent();
	}
}

void Game::UpdateQuit() {
	std::cout << "r: Recommencer, q: Quitter\n";
	char PlayedKey = im.GetKey();

	if (PlayedKey == 'r') {
		Initialize();
	}
	else if (PlayedKey == 'q') {
		std::cout << "Fermeture du jeu\n";
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
			std::cout << YELLOW << "Vous avez vaincu l'Empereur Orc et sauve le royaume !\n" << DEFAULT;
			em.RemoveEnnemies();
			system("pause");
			UpdateQuit();
		}
		else {
			std::cout << GREEN << "\nVous avez repousse les gobelins avec succes ! Vous reprenez la route.\n" << DEFAULT;

			int xpGagnee = nbEnnemis * 30;
			int moneyGagnee = nbEnnemis * 3;
			hm.Get(0).Train(xpGagnee);
			hm.Get(0).GainMoney(moneyGagnee);

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
			std::cout << RED << "\nMalheureusement vous vous etes fait vaincre...\n" << DEFAULT;
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
	std::cout << "[ Menu ]\n";
	std::cout << "P: Jouer, Q: Quitter, C: Credits\n";
	char MenuChoice = im.GetKey();

	switch (MenuChoice)
	{
	case 'p':
		std::cout << "Initialisation du jeu ...\n\n";
		Initialize();
		break;
	case 'q':
		std::cout << "Fermeture du jeu\n";
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
	std::cout << "Selection de la classe : 1: Warrior, 2: Mage, 3: Necromancien\n";
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
