#pragma once
#include "Character.h"

class Necromancer : public Character {
public:
    Necromancer(const std::string& n) : Character(n, 88, 88, 9, 1, 0, 100, true, false) {}

    void Attack(Character& target) override;
    bool Block() override;
};