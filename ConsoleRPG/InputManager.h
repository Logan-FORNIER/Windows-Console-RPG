#pragma once
#include <iostream>
#include <conio.h>

class InputManager
{
private:
	int role = 0;
	std::string nickname;

public:
	InputManager() {}

	void Render() const;
	std::string GetNickname() const;

	int NumberSecurity(int min, int max) const;

	char GetKey();
};

