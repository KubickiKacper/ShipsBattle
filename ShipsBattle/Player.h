#include "Ships.h"
#include "Board.h"


class Player
{
private:
    Board* board;
    Carier* carier;
    Battleship* battleship;
    Cruiser* cruiser;
    Submarine* submarine;
    Destroyer* destroyer;

	int shots;
	int hits;
    int player_id;

public:
    Player(int player_id) {
        this->player_id = player_id;
        this->shots = 0;
        this->hits = 0;
        board = new Board;
    }

    void place_ships()
    {
        carier = new Carier;
        carier->place_ship();
        
    }

    void getBoard() {
        board->show_board(this->player_id);
    }
};