#include "ship.h"

class Player{

private:
	string guessPos;

public:
	//virtual bool setShip() = 0;
	//virtual bool guess() = 0;
	//virtual int isValidPos(string desPos, int length) = 0;

	Player(){
		
	}

	void setCarrier();
	void setBattleship();
	void setSubmarine();
	void setCruiser();
	void setDestroyer();

protected:
	Board *board;

	string desPose;
	
	Ship *carrier;
	Ship *battleship;
	Ship *submarine;
	Ship *cruiser;
	Ship *destroyer;
		
	
};