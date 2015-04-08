#include "player.h"

class Computer : public Player{
private:
public:
	Computer(){
		board = new Board();
		/*carrier =		new Ship(5);
		battleship =	new Ship(4);
		submarine =		new Ship(3);
		cruiser =		new Ship(3);
		destroyer =		new Ship(2);*/
		choice = -1;
	}

	bool guess();
	bool setShip();
	int isValidPos(string desPos, int length);
};