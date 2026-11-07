#include "Orc.h"

void Orc::Attack(Character& target) {
	if (rage == 100) {
		cout << GetName() << " Donne un enorme coup de massue\n";
		target.TakeDamage(GetPower() + 8);
		rage = 0;
	}
	else {
		cout << GetName() << " Donne un coup de massue\n";
		target.TakeDamage(GetPower());
		rage += 12;
	}
}

bool Orc::Block() {
	IsBlocking = true;
	cout << GetName() << " pare le coup !\n";
	rage += 8;
	return IsBlocking;
}