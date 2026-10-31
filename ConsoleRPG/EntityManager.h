#pragma once
#include <vector>
#include <memory>
#include "Character.h"

using namespace std;

class EntityManager
{
private:
	vector<unique_ptr<Character>> heroes;

public:
	void Add(unique_ptr<Character> h);
	void UpdateAll();
	void RenderAll() const;
};
