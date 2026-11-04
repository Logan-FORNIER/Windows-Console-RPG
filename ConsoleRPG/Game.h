#pragma once
#include "HeroesManager.h"
#include "EnnemyManager.h"
#include "InputManager.h"
#include "Goblin.h"
#include "Mage.h"
#include "Warrior.h"

enum class GameState {
	Menu,
	Combat,
	Victory,
	Defeat,
	Quit
};

class Game
{
private:
	bool isRunning;
	GameState state;
	HeroesManager hm;
	EnnemyManager em;
	InputManager im;

public:
	void Update();
	void Menu();
	void CreditMenu();
	void UpdateCombat();

	void Initialize();
	void Loop();
	void Shutdown();
};

