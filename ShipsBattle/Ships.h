#include <vector>

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