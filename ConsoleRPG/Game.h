#pragma once
#include "HeroesManager.h"
#include "EnnemyManager.h"
#include "InputManager.h"
#include "Mage.h"
#include "Warrior.h"
#include "Goblin.h"
#include "Necromancer.h"
#include "Orc.h"
#include "EmperorOrc.h"

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RED "\033[31m"
#define DEFAULT "\033[0m"

enum class GameState {
	Menu,
	Exploration,
	Combat,
	Victory,
	Defeat,
	Quit
};

enum class LocationType {
	Village,
	Temple,
	Plaine
};

class Game
{
private:
	bool isRunning;
	bool isBossFight = false;
	GameState state;
	LocationType currentLocation;
	HeroesManager hm;
	EnnemyManager em;
	InputManager im;

public:
	void Update();

	EnnemyManager& GetEnemyManager() { return em; }

	void SetState(GameState newState) { state = newState; }
	
	void Menu();
	void CreditMenu();
	void UpdateCombat();
	void UpdateVictory();
	void UpdateDefeat();
	void UpdateQuit();
	void UpdateLocation();
	void GenerateRandomEvent();

	void Initialize();
	void Loop();
};
