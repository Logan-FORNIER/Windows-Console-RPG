#pragma once
#include <iostream>

using namespace std;

class Character
{
private:
	int Hp;
	int MaxHP;
	int Power;
	bool IsAlive;
	string name;

public:
	int GetMaxHp() const { return MaxHP; }
	int GetHp() const { return Hp; }
	int GetPower() const { return Power; }
	string GetName() const { return name; }

	void TakeDamage(int dmg);

	virtual void Attack(Character& target) = 0;

	bool isAlive() const;

	void Update();	
	void Render() const;

	Character(const string& n, int h, int hmax, int pwr) : name(n), Hp(h), MaxHP(hmax), Power(pwr) {}

	virtual ~Character() {
		cout << name << " est supprime.\n";
	}
};
