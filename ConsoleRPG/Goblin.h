#pragma once
#include "Character.h"

class Goblin : public Character
{
public:
	Goblin(const std::string& n) : Character(n, 50, 50, 6, 1, 0, 0, true, false) {}

	void Attack(Character& target) override;
	bool Block() override;
};
