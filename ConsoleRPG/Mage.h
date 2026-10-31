#pragma once
#include "Character.h"

class Mage : public Character
{
private:
	int mana;

public:
	Mage(const string& n) : Character(n, 80, 80, 15), mana(100) {}

	void Attack(Character& target) override;
};
