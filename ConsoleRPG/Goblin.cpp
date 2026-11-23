#include "Goblin.h"

void Goblin::Attack(Character& target) {
	std::cout << GetName() << " Donne un coup de griffe\n";
	target.TakeDamage(GetPower());
}

bool Goblin::Block() {
	IsBlocking = true;
	std::cout << GetName() << " Effectue contre griffe\n";
	return IsBlocking;
}