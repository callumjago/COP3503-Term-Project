#include "board.h"
#include "player.h"
#include "ship.h"

class User : public Player{
	private:

	public:
		Player(){
			board = new Board();

			carrier = new Ship(5);
			battleship = new Ship(4);
			submarine = new Ship(3);
			cruiser = new Ship(3);
			destroyer = new Ship(2);
		}

};
	

bool User :: setShip(){
	return false;
}

bool User :: guess(){
	return false;
}


int main(){

	return 0;
}