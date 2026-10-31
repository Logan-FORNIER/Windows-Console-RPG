#include "Character.h"

void Character::TakeDamage(int dmg) {
	Hp -= dmg;
	if (Hp <= 0) {
		Hp = 0;
		cout << name << " Est mort\n";
	}
}

void Character::Attack(Character& target) {
	target.TakeDamage(Power);
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

void Character::Render() const {
	cout << name << " - " << Hp << " / " << MaxHP << endl;
}