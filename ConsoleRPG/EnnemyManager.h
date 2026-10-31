#pragma once
#include <vector>
#include <memory>
#include "Character.h"

using namespace std;

class EnnemyManager
{
private:
	vector<unique_ptr<Character>> ennemy;

public:
	void Add(unique_ptr<Character> e);
	void UpdateAll();
	void RenderAll() const;

	size_t GetSize() const { return ennemy.size(); }
	
	Character& Get(size_t index);
};

