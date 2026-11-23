#include "Mage.h"

void Mage::Attack(Character& target) {
	if (mana < 16) {
		std::cout << GetName() << " Donne un coup de baton\n";
		target.TakeDamage(GetPower() - 8);
		mana += 7;
	}
	else
	{
		std::cout << GetName() << " Envoie une Boule de feu\n";
		target.TakeDamage(GetPower());
		mana -= 50;
	}
}

bool Mage::Block() {
	IsBlocking = true;
	std::cout << GetName() << " Invoque un bouclier\n";
	return IsBlocking;
}