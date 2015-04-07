#ifndef SHIP_H
#define SHIP_H
#include "board.h"

class Ship{
	public:
		bool sinkShip();	//attempts sinking the Ship (interp as setter method for state bool isSunk)
		bool getIsSunk();	//getter method for state bool isSunk
		int getLength();	//getter method for state int length
		Ship(int length, string name, bool isHorizontal, char startX, int startY);	//parametrized class constructor, input state int length
		void Initialize(Board b);
		
	private:
		int length;
		int startX;
		int startY;
		int* status;
		int* location;
		bool isSunk;
		bool isHorizontal;
		string name;
};
#endif
