#include "player.h"

class Computer : public Player{
private:

public:
	Computer()::guessPos(""){
		board = new Board();

		carrier = Ship(5);
		battleship = Ship(4);
		submarine = Ship(3);
		cruiser = Ship(3);
		destroyer = Ship(2);
	}
	bool setShip();
	bool guess();
	bool isValidPosition(string desiredPos);
};