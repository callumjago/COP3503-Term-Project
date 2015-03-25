#ifndef DATE_H
#define DATE_H


class Ship{
	public:
		bool sinkShip();	//attempts sinking the Ship (interp as setter method for state bool isSunk)
		bool getIsSunk();	//getter method for state bool isSunk
		int getLength();	//getter method for state int length
		Ship(int length);	//parametrized class constructor, input state int length

	private:
		int length;
		int* status;
		bool isSunk;
};


#endif
