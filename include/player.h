#include "ship.h"

class Player{
private:
public:
	//virtual bool setShip() = 0;
	//virtual bool guess() = 0;
	//virtual int isValidPos(string desPos, int length) = 0;

	Player(){
	}

	void setCarrier(bool &addSuccess);
	void setBattleship(bool &addSuccess);
	void setSubmarine(bool &addSuccess);
	void setCruiser(bool &addSuccess);
	void setDestroyer(bool &addSuccess);

	Board getBoard(){ return *board; };

	Board *board;
	
protected:
	

	string desPos;
	
	Ship *carrier;
	Ship *battleship;
	Ship *submarine;
	Ship *cruiser;
	Ship *destroyer;

	int choice;
	//bool addSuccess;

};