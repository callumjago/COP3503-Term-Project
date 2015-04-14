#ifndef USER_H
#define USER_H

#include "player.h"

class User: public Player{
private:

public:
	User(){
		board = new Board();
		choice = -1;
		//addSuccess = false;
	}

<<<<<<< HEAD
	
	int isValidPos(string desPos, int length, int* index);
	void setCarrier();
	void setBattleship();
	void setSubmarine();
	void setCruiser();
	void setDestroyer();
	
	bool guess(int* index);			
=======
	void setCarrier(bool &addSuccess);
	void setBattleship(bool &addSuccess);
	void setSubmarine(bool &addSuccess);
	void setCruiser(bool &addSuccess);
	void setDestroyer(bool &addSuccess);
	
	bool guess();		
	int isValidPos(string desPos, int length);

>>>>>>> Fleshed out user.cpp to set all ships.

};
#endif