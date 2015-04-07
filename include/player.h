#include "ship.h"

class Player{

private:
	string desPose;

public:
	virtual bool setShip() = 0;
	virtual bool guess() = 0;
	virtual int isValidPos(string desPos, int length) = 0;

	Player(){
		Board *board;
		Ship *carrier;
		Ship *battleship;
		Ship *submarine;
		Ship *cruiser;
		Ship *destroyer;
		
		string guessPos;
	}


		
	
};