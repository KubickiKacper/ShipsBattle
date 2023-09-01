#include <vector>
#include <conio.h>
#include <string>


class Ship {
protected:
	int length;
	std::vector<std::pair<int, int>> position;
	std::vector<std::pair<int, int>> hits;
	bool isAlive;
	
public:

	void setPosition(std::vector<std::pair<int, int>> position)
	{
		this->position = position;
	}

	std::vector<std::pair<int, int>> getPosition()
	{
		return this->position;
	}

	void show_ship_position(std::vector<std::pair<int, int>> init_position, const int board[10][10])
	{
		int board_copy[10][10];

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				board_copy[i][j] = board[i][j];
			}
		}

		for (const auto& pair : init_position)
		{
			board_copy[pair.first][pair.second] = 1;
		}

		for (int i = 0; i < 10; i++) {
			std::cout << "\n" << i + 1;

			if (i < 9) std::cout << "  ";
			else std::cout << " ";

			for (int j = 0; j < 10; j++) {
				std::cout << board_copy[i][j];
			}
		}
	}

	int place_ship(const int board[10][10])
	{
		
		int x = 0;
		int y = 0;

		std::vector<std::pair<int, int>> init_position;
		
		for (int i = 0; i < this->length; i++)
		{
			init_position.emplace_back(0,i);

		}

		for (const auto& pair : init_position) {
			std::cout << "(" << pair.first << ", " << pair.second << ")" << "\n";
		}

		char c;
		bool cant_move;
		bool horizontal = true;
		while (true)
		{
			c = _getch();
			std::cout << c;
			switch (c) {
			case 'w': case 'W':
			{
				cant_move=false;
				std::cout << "W";
				for (const auto& pair : init_position) {
					if (pair.first <= 0) {
						cant_move = true;
						break;
					}
				}

				std::cout << cant_move;
				if (cant_move) break;


				for (auto& pair : init_position) {
					pair.first -= 1;
				}

				for (const auto& pair : init_position) {
					std::cout << "(" << pair.first << ", " << pair.second << ")" << "\n";
				}

				show_ship_position(init_position, board);
				break;

			}

			case 'a': case 'A':
			{
				cant_move = false;
				std::cout << "A";

				for (const auto& pair : init_position) {
					if (pair.second <= 0) {
						cant_move = true;
						break;
					}
				}

				std::cout << cant_move;
				if (cant_move) break;
				for (auto& pair : init_position) {
					pair.second -= 1;
				}

				for (const auto& pair : init_position) {
					std::cout << "(" << pair.first << ", " << pair.second << ")" << "\n";
				}

				show_ship_position(init_position, board);
				break;
			}

			case 's': case 'S':
			{
				cant_move = false;
				std::cout << "S";

				for (const auto& pair : init_position) {
					if (pair.first >= 9) {
						cant_move = true;
						break;
					}
				}

				std::cout << cant_move;
				if (cant_move) break;
				for (auto& pair : init_position) {
					pair.first += 1;
				}

				for (const auto& pair : init_position) {
					std::cout << "(" << pair.first << ", " << pair.second << ")" << "\n";
				}

				show_ship_position(init_position, board);
				break;
			}


			case 'd': case 'D':
			{
				cant_move = false;
				std::cout << "D";

				for (const auto& pair : init_position) {
					if (pair.second >= 9) {
						cant_move = true;
						break;
					}
				}

				std::cout << cant_move;
				if (cant_move) break;

				for (auto& pair : init_position) {
					pair.second += 1;
				}

				for (const auto& pair : init_position) {
					std::cout << "(" << pair.first << ", " << pair.second << ")" << "\n";
				}

				show_ship_position(init_position, board);
				break;
			}
			case 'r': case 'R':
			{
				std::cout << "Rotation";
				int counter = 0;
				if (horizontal)
				{
					horizontal = !horizontal;
					for (auto& pair : init_position) {
						pair.first = 0;
						pair.second = counter;
						counter++;
					}
					break;
				}
				else
				{
					horizontal = !horizontal;
					for (auto& pair : init_position) {
						pair.first = counter;
						pair.second = 0;
						counter++;
					}
					break;
				}
			}
			
			case '\r':
			{
				return 1;
			}

			}


		}


	}
};

class Carier : public Ship {

public:
	Carier() {
		this->length = 5;
	}
};

class Battleship : public Ship {

public:
	Battleship() {
		this->length = 4;
	}
};

class Cruiser : public Ship {

public:
	Cruiser() {
		this->length = 3;
	}
};

class Submarine : public Ship {


public:
	Submarine() {
		this->length = 3;
	}
};

class Destroyer : public Ship {

public:
	Destroyer() {
		this->length = 2;
	}
};