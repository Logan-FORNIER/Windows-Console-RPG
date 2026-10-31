#pragma once
#include "HeroesManager.h"
#include "EnnemyManager.h"
#include "InputManager.h"
#include "Goblin.h"
#include "Mage.h"
#include "Warrior.h"

class Game
{
private:
	bool isRunning;
	HeroesManager hm;
	EnnemyManager em;
	InputManager im;

public:
	void initialize();
	void loop();
	void Shutdown();
};

