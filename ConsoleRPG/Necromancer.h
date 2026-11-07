#pragma once
#include "Character.h"

class Necromancer : public Character {
public:
    Necromancer(const string& n) : Character(n, 80, 80, 15, 1, 0) {}

    void Attack(Character& target) override;
    bool Block() override;
};