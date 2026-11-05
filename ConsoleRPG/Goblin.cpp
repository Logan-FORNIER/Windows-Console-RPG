#include "Goblin.h"

void Goblin::Attack(Character& target) {
	cout << GetName() << " Donne un coup de griffe\n";
	target.TakeDamage(GetPower());
}

void Goblin::Block() {
	cout << GetName() << " Effectue contre griffe\n";
}