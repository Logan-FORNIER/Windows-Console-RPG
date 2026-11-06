#include "Goblin.h"

void Goblin::Attack(Character& target) {
	cout << GetName() << " Donne un coup de griffe\n";
	target.TakeDamage(GetPower());
}

bool Goblin::Block() {
	IsBlocking = true;
	cout << GetName() << " Effectue contre griffe\n";
	return IsBlocking;
}