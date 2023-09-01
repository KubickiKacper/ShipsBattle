#include <iostream>
#include "Player.h"

class Game {
private:
    Player *p1;
    Player *p2;

public:
    void start_game()
    {
        p1->getBoard();
        p1->place_ships();
        //p2->getBoard();
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
