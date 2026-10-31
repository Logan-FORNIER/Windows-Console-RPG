#include "EntityManager.h"

using namespace std;

void EntityManager::Add(unique_ptr<Character> h) {
	heroes.push_back(move(h));
}

void EntityManager::UpdateAll() {
	for (auto& h : heroes)
		h->Update();
}

void EntityManager::RenderAll() const {
	for (auto& h : heroes)
		h->Render();
}