#include <iostream>
#include "HeroesManager.h"
#include "EnnemyManager.h"
#include "Warrior.h"
#include "Mage.h"
#include "Goblin.h"

using namespace std;

HeroesManager hm;
EnnemyManager em;

int main()
{
	hm.Add(make_unique<Warrior>("Ronan"));
	hm.Add(make_unique<Mage>("Icien"));

	em.Add(make_unique<Goblin>("Goblin"));

	hm.RenderAll();
	em.RenderAll();	

	hm.Get(0).Attack(em.Get(0));

	hm.RenderAll();
	em.RenderAll();

	return 0;
}