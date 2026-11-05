#include "Character.h"

void Character::TakeDamage(int dmg) {
	if (IsBlocking == true) {
		dmg -= BlockPower;
		if (dmg < 0) {
			dmg = 0;
		}

		IsBlocking = false;
	}

	Hp -= dmg;
	if (Hp <= 0) {
		Hp = 0;
		cout << name << " Est mort\n";
	}
}

void Character::Attack(Character& target) {
	target.TakeDamage(Power);
}

void Character::Block() {
	IsBlocking = true;
}

bool Character::isAlive() const {
	if (Hp <= 0) {
		return false;
	}
	else {
		return true;
	}
}

void Character::Update() {

}

void Character::Train(int xp) {
	Experience += xp;

	while (Experience >= nextLevelExperience)
	{
		Experience -= nextLevelExperience;
		Level++;
		nextLevelExperience *= 1.5;
	}

}

void Character::Render() const {
	cout << name << " - " << Hp << " / " << MaxHP << endl;
}