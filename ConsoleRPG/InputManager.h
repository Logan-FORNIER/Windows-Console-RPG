#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

class InputManager
{
public:
	InputManager() {}

	void Render() const;

	char GetKey();
};

