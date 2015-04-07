#include "player.h"

class Computer : public Player{
private:
public:
	Computer();
	string getGuessPos();
	bool guess();
	bool setShip();
	int isValidPosition(string desiredPos, int length);
};