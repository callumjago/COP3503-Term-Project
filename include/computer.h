#include "player.h"

class Computer : public Player{
private:
public:
	Computer();
	bool setShip();
	bool guess();
	int isValidPosition(string desiredPos, int length);
};