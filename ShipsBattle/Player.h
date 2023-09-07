#include "Ships.h"
#include "Board.h"


class Player
{
private:
    Board* board;
    std::vector<std::shared_ptr<Ship>> ShipsVector;

	int shots;
	int hits;
    int player_id;

public:
    Player(int player_id) {
        this->player_id = player_id;
        this->shots = 0;
        this->hits = 0;
        this->board = new Board;
        this->ShipsVector.push_back(std::make_shared<Carier>());
        this->ShipsVector.push_back(std::make_shared<Battleship>());
        this->ShipsVector.push_back(std::make_shared<Cruiser>());
        this->ShipsVector.push_back(std::make_shared<Submarine>());
        this->ShipsVector.push_back(std::make_shared<Destroyer>());
    }

    void place_ships()
    {
        std::vector<std::pair<int, int>> ship_positon;
        
        for (const auto& ship : this->ShipsVector)
        {
            ship_positon= ship->place_ship(this->board->getBoard());
            this->board->updateBoard(ship_positon);
            getBoard();
        }
    }

    void getBoard() {
        board->show_board(this->player_id);
    }
};