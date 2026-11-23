#pragma once
#include <iostream>

class Character
{
protected:
	float Hp;
	float MaxHP;
	float Power;
	float Experience;
	int Level;
	bool isAlive;
	bool isBlocking;
	float nextLevelExperience = 100;
	int Money;
	std::string name;

public:
	float GetMaxHp() const { return MaxHP; }
	float GetHp() const { return Hp; }
	float GetPower() const { return Power; }
	float GetExperience() const { return Experience; }
	int GetLevel() const { return Level; }
	int GetMoney() const { return Money; }
	float GetNextLevelExperience() const { return nextLevelExperience; }

	std::string GetName() const { return name; }

	void TakeDamage(float dmg);
	void TakeHeal(float heal);

	void Purchase(int money);
	void GainMoney(int money);

	void Train(int xp);

	virtual void Attack(Character& target) = 0;
	virtual bool Block() = 0;

	bool IsAlive() const;
	bool IsBlocking() const;

	void Update();	
	void Render() const;

	Character(const std::string& n, float h, float hmax, float pwr, int lvl, float xp, int money, bool alive, bool blocking) : name(n), Hp(h), MaxHP(hmax), Power(pwr), Level(lvl), Experience(xp), Money(money), isAlive(alive), isBlocking(blocking) {}

	virtual ~Character() {
		std::cout << name << " est supprime.\n";
	}
};
