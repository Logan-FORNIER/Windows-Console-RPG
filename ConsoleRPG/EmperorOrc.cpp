#include "EmperorOrc.h"

void EmperorOrc::Attack(Character& target) {
	if (rage == 100) {
		std::cout << GetName() << " Donne un giga coup de massue\n";
		target.TakeDamage(GetPower() + 18);
		rage = 0;
	}
	else {
		std::cout << GetName() << " Donne un enorme coup de massue\n";
		target.TakeDamage(GetPower());
		rage += 15;
	}
}

bool EmperorOrc::Block() {
	IsBlocking = true;
	std::cout << GetName() << " pare le coup !\n";
	rage += 10;
	return IsBlocking;
}
