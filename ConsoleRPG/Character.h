#pragma once
#include <iostream>

using namespace std;

class Character
{
private:
	int Hp;
	int MaxHP;
	int Power;
	int BlockPower;
	int Experience;
	int Level;
	bool IsAlive;
	bool IsBlocking;
	string name;

public:
	int GetMaxHp() const { return MaxHP; }
	int GetHp() const { return Hp; }
	int GetPower() const { return Power; }
	int GetBlockPower() const { return BlockPower; }
	int GetExperience() const { return Experience; }
	int GetLevel() const { return Level; }
	string GetName() const { return name; }

	void TakeDamage(int dmg);

	void Train(int xp);

	virtual void Attack(Character& target) = 0;
	virtual void Block(Character& target) = 0;

	bool isAlive() const;
	bool isBlocking() const;

	void Update();	
	void Render() const;

	Character(const string& n, int h, int hmax, int pwr, int bpwr) : name(n), Hp(h), MaxHP(hmax), Power(pwr), BlockPower(bpwr) {}

	virtual ~Character() {
		cout << name << " est supprime.\n";
	}
};
