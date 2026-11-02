#pragma once
#include "Character.h"

class Goblin : public Character
{
public:
	Goblin(const string& n) : Character(n, 50, 50, 8, 4) {}

	void Attack(Character& target) override;
	void Block(Character& target) override;
};
