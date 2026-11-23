#include "InputManager.h"

void InputManager::Render() const {
	std::cout << "Touche a : Attaquer, Touche D : Defendre, Touche  F : Fuir\n";
}

std::string InputManager::GetNickname() const {
	std::string name = nickname;
	std::cout << "Renseigner votre pseudonyme :\n";
	std::cin >> name;

	return name;
}

int InputManager::NumberSecurity(int min, int max) const {
	int value;
	
	while (true) {
		std::cin >> value;
		if (std::cin.fail() || value < min || value > max) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Entrez un nombre entre " << min << " et " << max << std::endl;
		}
		else {
			return value;
		}
	}
}

char InputManager::GetKey() {
	char ch = _getch();

	return ch;
}