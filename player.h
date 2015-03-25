#include "board.h"

class Player{
	public:
		virtual bool setShip() = 0;
		virtual bool guess() = 0;

	private:
		Board board;
		//Cannot declare ships until the ship.h file is created.
		/*Ship carrier;
		Ship battleship;
		Ship submarine;
		Ship cruiser;
		Ship destroyer;*/
		string guessPos;
};