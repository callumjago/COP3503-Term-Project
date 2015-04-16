#include "user.h"

class Computer : public Player{
private:
public:
	Computer(){
		board = new Board();
		choice = -1;
	}

	void setCarrier(bool *addSuccess);
	void setBattleship(bool *addSuccess);
	void setSubmarine(bool *addSuccess);
	void setCruiser(bool *addSuccess);
	void setDestroyer(bool *addSuccess);

	int guess();
	int formulate(int length);
	int isValidPos(string desPos, int length);
};