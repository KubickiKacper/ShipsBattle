#include "Ships.h"
#include "Board.h"


class Player
{
private:
    Board* board;
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

    void getBoard() {
        board->show_board(this->player_id);
    }
};