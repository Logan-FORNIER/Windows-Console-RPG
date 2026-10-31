#include "Goblin.h"

void Goblin::Attack(Character& target) {
	cout << GetName() << " Coup de griffe\n";
	target.TakeDamage(GetPower());
}