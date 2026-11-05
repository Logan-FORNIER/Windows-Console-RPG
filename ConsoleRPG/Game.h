#pragma once
#include "HeroesManager.h"
#include "EnnemyManager.h"
#include "InputManager.h"
#include "Mage.h"
#include "Warrior.h"
#include "Goblin.h"

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
