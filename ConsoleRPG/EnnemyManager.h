#pragma once
#include <vector>
#include <memory>
#include "Character.h"

class EnnemyManager
{
private:
	std::vector<std::unique_ptr<Character>> ennemy;

public:
	void Add(std::unique_ptr<Character> e);
	void UpdateAll();
	void RenderAll() const;
	void RemoveEnnemies();

	size_t GetSize() const { return ennemy.size(); }
	
	Character& Get(size_t index);
};

