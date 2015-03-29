#ifndef DATE_H
#define DATE_H
#include "board.h"


class Ship{
	private:
		int length;
		int* status;
		bool isSunk;
	
	public:
		bool sinkShip();	//attempts sinking the Ship (interp as setter method for state bool isSunk)
		bool getIsSunk();	//getter method for state bool isSunk
		int getLength();	//getter method for state int length

		Ship(int len){
			length = len;
			isSunk = false;
		};	//parametrized class constructor, input state int length

	
};

#endif
