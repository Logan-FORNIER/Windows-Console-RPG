#include "Warrior.h"

void Warrior::Attack(Character& target) {
	cout << "Donne un coup d'epee\n";
	target.TakeDamage(GetPower());
}