#pragma once
#include "Character.h"

class Goblin : public Character
{
public:
	Goblin(const string& n) : Character(n, 50, 50, 8) {}
};
