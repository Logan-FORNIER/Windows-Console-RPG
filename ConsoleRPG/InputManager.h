#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

class InputManager
{
private:
	char ch;

public:
	InputManager() {}

	char GetKey() {
		ch = _getch();

		return ch;
	}
};

