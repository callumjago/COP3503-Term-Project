#include "ship.h"

class Player{
public:
	virtual bool setShip() = 0;
	virtual bool guess() = 0;
	virtual int isValidPos(string desPos, int length) = 0;
	Player(){
		carrier = Ship(5);
		battleship = Ship(4);
		submarine = Ship(3);
		cruiser = Ship(3);
		destroyer = Ship(2);
	}

private:
		
protected:
	Board *board;

	Ship *carrier;
	Ship *battleship;
	Ship *submarine;
	Ship *cruiser;
	Ship *destroyer;

	string guessPos;
};