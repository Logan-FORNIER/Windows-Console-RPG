#include "Character.h"

void Character::TakeDamage(int dmg) {
	Hp -= dmg;
	if (Hp <= 0) {
		Hp = 0;
		cout << name << "Est  mort";
	}
}

void Character::Attack(Character& target) {
	target.TakeDamage(Power);
}

void Character::Update() {

}

void Character::Render() const {
	cout << name << " - " << Hp << " / " << MaxHP << endl;
}