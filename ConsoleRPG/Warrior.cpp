#include "Warrior.h"

void Warrior::Attack(Character& target) {
	cout << GetName() << " Donne un coup d'epee\n";
	target.TakeDamage(GetPower());
}

void Warrior::Block(Character& target) {
	cout << GetName() << " Part le coup\n";
	target.TakeDamage(GetPower());
}