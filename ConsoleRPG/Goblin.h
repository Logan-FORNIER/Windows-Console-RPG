#pragma once
#include "Character.h"

class Goblin : public Character
{
public:
	Goblin(const string& n) : Character(n, 50, 50, 6, 1, 0, 0) {}

	void Attack(Character& target) override;
	bool Block() override;
};
