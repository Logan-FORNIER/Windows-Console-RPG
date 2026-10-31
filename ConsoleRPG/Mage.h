#pragma once
#include "Character.h"

class Mage : public Character
{
private:
	int mana;

public:
	Mage(const string& n) : Character(n, 120, 120, 12), mana(100) {}
};
