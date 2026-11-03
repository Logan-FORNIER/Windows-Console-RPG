#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

class InputManager
{
private:
	int role;
	string nickname;

public:
	InputManager() {}

	void Render() const;
	string GetNickname() const;
	int GetRole() const;

	int NumberSecurity(int min, int max) const;

	char GetKey();
};

