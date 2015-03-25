#include "board.h"
#include "player.h"
#include "ship.h"

class Computer: public Player{
	public:
		Computer();
};

Computer::Computer():guessPos(""){
	board = new Board();
	board.populate();

	carrier = new Ship(5);
	battleship = new Ship(4);
	submarine = new Ship(3);
	cruiser = new Ship(3);
	destroyer = new Ship(2);
}

bool Computer::setShip(){
	return false;
}

bool Computer::guess(){
	return false;
}