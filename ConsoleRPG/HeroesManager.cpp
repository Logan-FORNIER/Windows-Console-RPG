#include "HeroesManager.h"


using namespace std;

void HeroesManager::Add(unique_ptr<Character> h) {
	heroes.push_back(move(h));
}

void HeroesManager::UpdateAll() {
	for (auto& h : heroes)
		h->Update();
}

void HeroesManager::RenderAll() const {
	cout << "Hero :\n";
	for (auto& h : heroes)
		h->Render();
	cout << endl;
}

Character& HeroesManager::Get(size_t index) {
	return *heroes[index];
}