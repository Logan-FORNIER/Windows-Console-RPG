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

void Character::Block(Character& target) {
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

/* void Character::Train(int xp) {
	Experience += xp;
	Level = 1;

	// lvl 2 = 100 xp puis ont multiplie par 1.5 pour chaque monté en level donc level 3 = 150

	Level1 = 0;
	level2 = 100;
	level3 = 150;
	level4 = 225;

	if (Experience == 100) {
		Level += 1;
	}
	else if (Experience == (Experience * 1.5)) {
		Level += 1;
	}
}

*/

void Character::Render() const {
	cout << name << " - " << Hp << " / " << MaxHP << endl;
}