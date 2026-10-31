#include "EntityManager.h"

using namespace std;

void EntityManager::Add(unique_ptr<Character> h) {
	heroes.push_back(move(h));
}