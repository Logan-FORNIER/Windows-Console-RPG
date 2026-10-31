#include "Character.h"

void Character::TakeDamage(int dmg) {
	Hp -= dmg;
	if (Hp <= 0) {
		Hp = 0;
		cout << name << "Est  mort";
	}
}