#include "EmperorOrc.h"

void EmperorOrc::Attack(Character& target) {
	if (rage == 100) {
		cout << GetName() << " Donne un giga coup de massue\n";
		target.TakeDamage(GetPower() + 18);
		rage = 0;
	}
	else {
		cout << GetName() << " Donne un enorme coup de massue\n";
		target.TakeDamage(GetPower());
		rage += 15;
	}
}

bool EmperorOrc::Block() {
	IsBlocking = true;
	cout << GetName() << " pare le coup !\n";
	rage += 10;
	return IsBlocking;
}
