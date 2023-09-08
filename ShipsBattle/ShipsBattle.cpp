#include <iostream>
#include "Player.h"

class Game {
private:
    Player *p1;
    Player *p2;

public:
    void start_game()
    {
        p1->place_ships();
        p2->create_enemy_board(p1->board->getBoard());
        p1->board->setBoard(p2->shot());
        p1->board->setBoard(p2->shot());
        p1->board->setBoard(p2->shot());
    }
    
    Game() {
        p1 = new Player(1);
        p2 = new Player(2);
    }
};

int main()
{
    Game game;
    game.start_game();

}
