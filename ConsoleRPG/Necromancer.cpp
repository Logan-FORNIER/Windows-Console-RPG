#include "Necromancer.h"

using namespace std;

void Necromancer::Attack(Character& target) {
    cout << GetName() << " lance un sort d'aspiration d'ame sur " << target.GetName() << " et draine son Energy Vital !\n";

    target.TakeDamage(Power);

    float lifesteal = Power * 0.3f;
    Hp += lifesteal;

    if (Hp > MaxHP) {
        Hp = MaxHP;
    }
}

bool Necromancer::Block() {
    IsBlocking = true;
    cout << GetName() << " s'entoure d'un voile d'ombres\n";
    return true;
}