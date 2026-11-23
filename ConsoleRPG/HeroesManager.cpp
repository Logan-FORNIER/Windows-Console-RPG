#include "HeroesManager.h"

void HeroesManager::Add(std::unique_ptr<Character> h) {
	heroes.push_back(move(h));
}

void HeroesManager::UpdateAll() {
	for (auto& h : heroes)
		h->Update();
}

void HeroesManager::RenderAll() const {
	std::cout << "Hero :\n";
	for (auto& h : heroes)
		h->Render();
	std::cout << std::endl;
}

void HeroesManager::RemoveHero() {
	int i = 0;

	while (i < static_cast<int>(heroes.size())) {
		heroes.erase(heroes.begin() + i);
	}
}

Character& HeroesManager::Get(size_t index) {
	return *heroes[index];
}