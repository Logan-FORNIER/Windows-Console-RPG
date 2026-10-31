#include <iostream>
#include "HeroesManager.h"
#include "Warrior.h"
#include "Mage.h"
#include "Goblin.h"

using namespace std;

HeroesManager hm;

int main()
{
	hm.Add(make_unique<Warrior>("Ronan"));
	hm.Add(make_unique<Mage>("Icien"));

	hm.RenderAll();

	return 0;
}