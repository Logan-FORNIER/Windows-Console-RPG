#include "InputManager.h"

using namespace std;

void InputManager::Render() const {
	cout << "Touche a : Attaquer, Touche D : Defendre, Touche  F : Fuir\n";
}

string InputManager::GetNickname() const {
	string name = nickname;
	cout << "Renseigner votre pseudonyme :\n";
	cin >> name;

	return name;
}

int InputManager::NumberSecurity(int min, int max) const {
	int value;
	
	while (true) {
		cin >> value;
		if (cin.fail() || value < min || value > max) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Entrez un nombre entre " << min << " et " << max << endl;
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