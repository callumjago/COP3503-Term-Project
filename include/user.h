#ifndef USER_H
#define USER_H

#include "player.h"

class User: public Player{
private:

public:
	User(){
		board = new Board();
		/*carrier = new Ship(5);
		battleship = new Ship(4);
		submarine = new Ship(3);
		cruiser = new Ship(3);
		destroyer = new Ship(2);*/
		choice = -1;
	}

	void setCarrier();
	void setBattleship();
	void setSubmarine();
	void setCruiser();
	void setDestroyer();
	
	bool guess();		
	int isValidPos(string desPos, int length);	
};
#endif