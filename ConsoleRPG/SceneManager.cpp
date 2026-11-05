#include "SceneManager.h"
#include "Game.h"

void SceneManager::RandLocation(Character& target) {
	int randomIndex = rand() % allLocation.size();

	allLocation[randomIndex]->LocationEnter(*currentGame, target);
}