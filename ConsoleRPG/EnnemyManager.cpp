#include "EnnemyManager.h"

using namespace std;

void EnnemyManager::Add(unique_ptr<Character> e) {
	ennemy.push_back(move(e));
}

void EnnemyManager::UpdateAll() {
	for (auto& h : ennemy)
		h->Update();
}

void EnnemyManager::RenderAll() const {
	for (auto& h : ennemy)
		h->Render();
}

Character& EnnemyManager::Get(size_t index) {
	return *ennemy[index];
}