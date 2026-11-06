#pragma once
#include  "Character.h"

using namespace std;

class Warrior : public Character
{
private:
	int rage;

public:
	Warrior(const string& n) : Character(n, 120, 120, 12, 1, 0), rage(0) {}

	void Attack(Character& target) override;
	bool Block() override;
};
