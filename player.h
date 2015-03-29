#include "board.h"
#include "ship.h"

class Player{
	public:
		virtual bool setShip() = 0;
		virtual bool guess() = 0;

	private:
		Board board;
		
		Ship carrier;
		Ship battleship;
		Ship submarine;
		Ship cruiser;
		Ship destroyer;

		string guessPos;
};
