#include "Mage.h"

void Mage::Attack(Character& target) {
	cout << GetName() << " Envoie une Boule de feu\n";
	target.TakeDamage(GetPower());
}

void Mage::Block(Character& target) {
	cout << GetName() << " Contre le coup\n";
	target.TakeDamage(GetPower());
}