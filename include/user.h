#include "player.h"

class User: public Player{
private:

public:
	User(){
		/*board = new Board();

		carrier = Ship(5);
		battleship = Ship(4);
		submarine = Ship(3);
		cruiser = Ship(3);
		destroyer = Ship(2);*/
	}
	bool setShip();		//Eion: I think these function declarations are redundant sincce they are already declared in player.h?
	bool guess();		//""
	void isValidPosition(string desiredPos, int length);	//""
};
	

bool User :: setShip(){
	return false;
};

