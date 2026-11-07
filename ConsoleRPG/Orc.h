#pragma once
#include "Character.h"

class Orc : public Character
{
private:
    int rage;
public:
    Orc(const string& n) : Character(n, 120, 120, 13, 1, 0), rage(0) {}

    void Attack(Character& target) override;
    bool Block() override;
};
