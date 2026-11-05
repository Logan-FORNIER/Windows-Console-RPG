#include "Village.h"

void Village::LocationEnter(Game& game, Character& target) {
	cout << "Vous etes arrive au Village\n";

	int luck = rand() % 5;
	if (luck == 0) {
		cout << "Un Villageois s'approche et vous demande si vous voulez taffer les abdos avec lui\n";

		int XP = rand() % 37;

		target.Train(XP);
	}
	else
	{
		cout << "Un village calme sans grand interet\n";
	}
}