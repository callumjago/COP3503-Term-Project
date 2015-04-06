#include "player.h"

class User: public Player{
private:

public:
	User(){
		board = new Board();

		carrier = new Ship(5);
		battleship = new Ship(4);
		submarine = new Ship(3);
		cruiser = new Ship(3);
		destroyer = new Ship(2);
	}
	bool setShip();	
	bool guess();		
	int isValidPos(string desPos, int length);	
};
