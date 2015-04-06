#include "ship.h"

class Player{

public:
<<<<<<< HEAD
	virtual bool setShip() = 0;
	virtual bool guess() = 0;
	virtual int isValidPos(string desPos, int length) = 0;
=======

	Player(){
		carrier = new Ship(5);
		battleship = new Ship(4);
		submarine = new Ship(3);
		cruiser = new Ship(3);
		destroyer = new Ship(2);
	}
>>>>>>> 1f89c432a1b9c4c181ee51b8bfda2ec9aae0befa

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
		
	Board *board;
	Ship *carrier;
	Ship *battleship;
	Ship *submarine;
	Ship *cruiser;
	Ship *destroyer;
	string guessPos;
};