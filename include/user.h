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
	
	int isValidPos(string desPos, int length);
	void setCarrier(bool *addSuccess);
	void setBattleship(bool *addSuccess);
	void setSubmarine(bool *addSuccess);
	void setCruiser(bool *addSuccess);
	void setDestroyer(bool *addSuccess);
	
	int guess();			
};
#endif