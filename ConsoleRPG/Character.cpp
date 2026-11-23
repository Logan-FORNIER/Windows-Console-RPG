#include "Character.h"

void Character::TakeDamage(float dmg) {
	if (isBlocking == true) {
		dmg /= 2;
		if (dmg < 0) {
			dmg = 0;
		}

		isBlocking = false;
	}

	Hp -= dmg;
	if (Hp <= 0) {
		Hp = 0;
		std::cout << name << " Est mort\n";
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
		std::cout << "Vous n'avez plus d'argent !";
	}
}

void Character::GainMoney(int money) {
	Money += money;
}

void Character::Attack(Character& target) {
	target.TakeDamage(Power);
}

bool Character::Block() {
	isBlocking = true;
	return isBlocking;
}

bool Character::IsAlive() const {
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
	std::cout << GetName() << " gagne " << xp << " Point d'xp !\n";

	while (Experience >= nextLevelExperience)
	{
		Experience -= nextLevelExperience;
		Level++;
		nextLevelExperience *= 1.5;

		Power *= 1.05f;

		std::cout << "Niveau superieur ! Vous passez niveau " << Level << " !\n";
	}
}

void Character::Render() const {
	std::cout << "Level : " << Level << " Experience " << Experience << " / " << nextLevelExperience << " " << name << " - " << Hp << " / " << MaxHP << " Money : " << Money << " Piece de cuivre" << std::endl;
}