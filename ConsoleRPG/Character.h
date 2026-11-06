#pragma once
#include <iostream>

using namespace std;

class Character
{
protected:
	float Hp;
	float MaxHP;
	float Power;
	int Experience;
	int Level;
	bool IsAlive;
	bool IsBlocking;
	float nextLevelExperience = 100;
	string name;

public:
	float GetMaxHp() const { return MaxHP; }
	float GetHp() const { return Hp; }
	float GetPower() const { return Power; }
	int GetExperience() const { return Experience; }
	int GetLevel() const { return Level; }
	float GetNextLevelExperience() const { return nextLevelExperience; }

	string GetName() const { return name; }

	void TakeDamage(float dmg);

	void Train(int xp);

	virtual void Attack(Character& target) = 0;
	virtual bool Block() = 0;

	bool isAlive() const;
	bool isBlocking() const;

	void Update();	
	void Render() const;

	Character(const string& n, int h, int hmax, int pwr, int lvl, int xp) : name(n), Hp(h), MaxHP(hmax), Power(pwr), Level(lvl), Experience(xp) {}

	virtual ~Character() {
		cout << name << " est supprime.\n";
	}
};
