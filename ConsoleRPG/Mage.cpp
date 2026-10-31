#include "Mage.h"

void Mage::Attack(Character& target) {
	cout << GetName() << " Envoie une Boule de feu\n";
	target.TakeDamage(GetPower());
}