#include "Character.h"

void Character::TakeDamage(float dmg) {
	if (IsBlocking == true) {
		dmg /= 2;
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

void Character::TakeHeal(float heal) {
	Hp += heal;
	if (Hp >= MaxHP) {
		Hp = MaxHP;
	}
}

void Character::Purchase(int money) {
	Money -= money;
	if (Money == 0) {
		cout << "Vous n'avez plus d'argent !";
	}
}

void Character::GainMoney(int money) {
	Money += money;
}

void Character::Attack(Character& target) {
	target.TakeDamage(Power);
}

bool Character::Block() {
	IsBlocking = true;
	return IsBlocking;
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
	cout << GetName() << " gagne " << xp << " Point d'xp !\n";

	while (Experience >= nextLevelExperience)
	{
		Experience -= nextLevelExperience;
		Level++;
		nextLevelExperience *= 1.5;

		Power *= 1.05;

		cout << "Niveau superieur ! Vous passez niveau " << Level << " !\n";
	}
}

void Character::Render() const {
	cout << "Level : " << Level << " Experience " << Experience << " / " << nextLevelExperience << " " << name << " - " << Hp << " / " << MaxHP << " Money : " << Money << " Piece de cuivre" << endl;
}