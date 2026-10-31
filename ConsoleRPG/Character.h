#pragma once
#include <iostream>

using namespace std;

class Character
{
private:
	int Hp;
	int MaxHP;
	int Power;
	string name;

public:
	int GetMaxHp() const { return MaxHP; }
	int GetHp() const { return Hp; }
	int GetPower() const { return Power; }
	string GetName() const { return name; }

	void TakeDamage(int dmg);

	virtual void Attack() = 0;

	Character(const string& n, int h, int hmax, int pwr) : name(n), Hp(h), MaxHP(hmax), Power(pwr) {}

	virtual ~Character() {
		cout << name << "est supprime.\n";
	}
};
