#include "Goblin.h"

void Goblin::Attack(Character& target) {
	cout << GetName() << " Donne un coup de griffe\n";
	target.TakeDamage(GetPower());
}

void Goblin::Block(Character& target) {
	cout << GetName() << " Effectue contre griffe\n";
	target.TakeDamage(GetPower());
}