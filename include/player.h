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

void setCarrier(){
	std::cout << carrier->getIsSunk();
}
void setBattleship(){
	std::cout << battleship->getIsSunk();
}
void setSubmarine(){
	std::cout << submarine->getIsSunk();
}
void setCruiser(){
	std::cout << cruiser->getIsSunk();
}
void setDestroyer(){
	std::cout << destroyer->getIsSunk();
}
		
	
};