#pragma once
#include <iostream>

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
	int Money;
	std::string name;

public:
	float GetMaxHp() const { return MaxHP; }
	float GetHp() const { return Hp; }
	float GetPower() const { return Power; }
	int GetExperience() const { return Experience; }
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

	bool isAlive() const;
	bool isBlocking() const;

	void Update();	
	void Render() const;

	Character(const std::string& n, int h, int hmax, int pwr, int lvl, int xp, int money) : name(n), Hp(h), MaxHP(hmax), Power(pwr), Level(lvl), Experience(xp), Money(money) {}

	virtual ~Character() {
		std::cout << name << " est supprime.\n";
	}
};
