#include "InputManager.h"

void InputManager::Render() const {
	cout << "Touche a : Attaquer, Touche D : Defendre, Touche  F : Fuir\n";
}

char InputManager::GetKey() {
	char ch = _getch();

	return ch;
}