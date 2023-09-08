#include <string>
#include <iostream>
std::string alphabet = "abcdefghij";

class Board {
private:
	int board[10][10];

public:
    void setBoard(const int newBoard[10][10])
    {
        std::memcpy(board, newBoard, sizeof(board));
    }

    int (*getBoard())[10]
    {
        return this->board;
    }

	Board() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                this->board[i][j] = 0; // 0 = empty space, 1 = ship, 2 = hit, 3 = miss
            }
        }
    }
    
    Board(const int board[10][10])
    {
        setBoard(board);
    }

    void show_board(int player_id) {
        std::cout << "Player " << player_id << " board:\n   ";

        for (auto c : alphabet)
        {
            std::cout << c;
        }


        for (int i = 0; i < 10; i++) {
            std::cout << "\n" << i + 1;

            if (i < 9) std::cout << "  ";
            else std::cout << " ";


            for (int j = 0; j < 10; j++) {
                std::cout << this->board[i][j];
            }
        }

        std::cout << "\n";
    }

    void show_board_to_shot(int x, int y)
    {
        for (auto c : alphabet)
        {
            std::cout << c;
        }

        for (int i = 0; i < 10; i++) {
            std::cout << "\n" << i + 1;

            if (i < 9) std::cout << "  ";
            else std::cout << " ";

            for (int j = 0; j < 10; j++) {
                if (i==y && j==x) std::cout << "X";
                else if (this->board[i][j] == 0 || this->board[i][j] == 1) std::cout << "~";
                else if (this->board[i][j] == 2) std::cout << "*";
                else if (this->board[i][j] == 3) std::cout << "#";
            }
        }
    }

    void updateBoard(std::vector<std::pair<int, int>> ship_position)
    {
        for (auto p : ship_position)
        {
            this->board[p.first][p.second] = 1;
        }
    }
};