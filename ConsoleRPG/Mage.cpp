#include "Mage.h"

void Mage::Attack(Character& target) {
	if (mana < 16) {
		cout << GetName() << " Donne un coup de baton\n";
		target.TakeDamage(GetPower() - 8);
		mana += 7;
	}
	else
	{
		cout << GetName() << " Envoie une Boule de feu\n";
		target.TakeDamage(GetPower());
		mana -= 50;
	}
}

void Mage::Block(Character& target) {
	cout << GetName() << " Contre le coup\n";
	target.TakeDamage(GetPower());
}