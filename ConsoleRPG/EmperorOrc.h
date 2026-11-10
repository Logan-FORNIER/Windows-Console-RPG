#pragma once
#include "Character.h"

class EmperorOrc : public Character
{
private:
    int rage;
public:
    EmperorOrc(const string& n) : Character(n, 532, 532, 28, 1, 0, 0), rage(0) {}

    void Attack(Character& target) override;
    bool Block() override;
};
