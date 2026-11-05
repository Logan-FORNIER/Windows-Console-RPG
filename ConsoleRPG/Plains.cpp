#include "Plains.h"
#include "Game.h"
#include "Goblin.h"

void Plains::LocationEnter(Game& game, Character& target) {
    cout << "Vous etes arriver dans une plaine\n";

    int luck = rand() % 2;

    if (luck == 0) {
        cout << "Une embuscade par des gobelins !\n";

        game.GetEnemyManager().RemoveEnnemies();
        game.GetEnemyManager().Add(make_unique<Goblin>("Goblin"));
        game.GetEnemyManager().Add(make_unique<Goblin>("Goblin"));
        game.GetEnemyManager().Add(make_unique<Goblin>("Goblin"));

        game.SetState(GameState::Combat);
    }
    else
    {
        cout << "La route est calme\n";
    }
}