#include "Ships.h"
#include "Board.h"


class Player
{
private:
    //Board* board;
	Board* enemy_board;
    std::vector<std::shared_ptr<Ship>> ShipsVector;
	int shots;
	int hits;
    int player_id;

public:
	Board* board;
	
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
            ship_positon = ship->place_ship(this->board->getBoard());
            this->board->updateBoard(ship_positon);
			this->board->show_board(this->player_id);
        }
    }

	void create_enemy_board(const int board[10][10])
	{
		this->enemy_board = new Board(board);
	}

	int(*shot())[10]
    {
		int x = 0;
		int y = 0;
		char c;

		while (true)
		{
			c = _getch();
			std::cout << c;
			
			switch (c) {
			case 'w': case 'W':
			{
				if (y <= 0) {
					break;
				}
				y--;
				break;
			}

			case 'a': case 'A':
			{
				std::cout << "A";
				if (x <= 0) {
					break;
				}
				x--;
				break;
			}

			case 's': case 'S':
			{
				std::cout << "S";
				if (y >= 9) {
					break;
				}
				y++;
				break;
			}


			case 'd': case 'D':
			{
				std::cout << "D";
				if (x >= 9) {

					break;
				}
				x++;
				break;
			}

			case '\r':
			{
				int(*enemy_board_copy)[10] = this->enemy_board->getBoard();

				if (enemy_board_copy[y][x] == 1)
				{
					std::cout << "\nHit\n";
					enemy_board_copy[y][x] = 2;
				}
				else if (enemy_board_copy[y][x] == 0)
				{
					std::cout << "\Miss\n";
					enemy_board_copy[y][x] = 3;
				}

				this->enemy_board->setBoard(enemy_board_copy);

				return enemy_board_copy;
				break;
			}
			}

			this->enemy_board->show_board_to_shot(x, y);
		}
	}
};