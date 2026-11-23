#pragma once
#include  "Character.h"

class Warrior : public Character
{
private:
	int rage;

public:
	Warrior(const std::string& n) : Character(n, 120, 120, 12, 1, 0, 100), rage(0) {}

	void Attack(Character& target) override;
	bool Block() override;
};
