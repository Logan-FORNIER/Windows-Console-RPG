#include "Warrior.h"

void Warrior::Attack(Character& target) {
	if (rage == 100) {
		cout << GetName() << " Donne un enorme coup d'epee\n";
		target.TakeDamage(GetPower() + 8);
		rage = 0;
	}
	else {
		cout << GetName() << " Donne un coup d'epee\n";
		target.TakeDamage(GetPower());
		rage += 12;
	}
}

bool Warrior::Block() {
	IsBlocking = true;
	cout << GetName() << " pare le coup !\n";
	return IsBlocking;
}