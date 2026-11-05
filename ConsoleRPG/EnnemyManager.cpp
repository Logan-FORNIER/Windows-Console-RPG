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
	cout << "Ennemies :\n";
	for (auto& h : ennemy)
		h->Render();
	cout << endl;
}

void EnnemyManager::RemoveEnnemies() {
	int i = 0;

	while (i < static_cast<int>(ennemy.size())) {
		ennemy.erase(ennemy.begin() + i);
	}
}

Character& EnnemyManager::Get(size_t index) {
	return *ennemy[index];
}