#include "Orc.h"

void Orc::Attack(Character& target) {
	if (rage == 100) {
		std::cout << GetName() << " Donne un enorme coup de massue\n";
		target.TakeDamage(GetPower() + 8);
		rage = 0;
	}
	else {
		std::cout << GetName() << " Donne un coup de massue\n";
		target.TakeDamage(GetPower());
		rage += 12;
	}
}

bool Orc::Block() {
	IsBlocking = true;
	std::cout << GetName() << " pare le coup !\n";
	rage += 8;
	return IsBlocking;
}