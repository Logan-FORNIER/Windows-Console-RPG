#pragma once
#include <vector>
#include <memory>
#include "Character.h"

class HeroesManager
{
private:
	std::vector<std::unique_ptr<Character>> heroes;

public:
	void Add(std::unique_ptr<Character> h);
	void UpdateAll();
	void RenderAll() const;
	void RemoveHero();

	size_t GetSize() const { return heroes.size(); }

	Character& Get(size_t index);
};
