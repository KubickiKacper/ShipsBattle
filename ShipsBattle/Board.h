#include <string>
#include <iostream>
std::string alphabet = "abcdefghij";

class Board {
private:
	int board[10][10];

public:
	Board() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                this->board[i][j] = 0;
            }
        }
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
};