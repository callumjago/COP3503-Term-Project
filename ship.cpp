#include "battleship_main.h"

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

Ship::Ship(int length):length(length), status(NULL), isSunk(false){
	//perhaps do something for state int* status
	if(length < 0){ this->length = 0; }
}

bool Ship::sinkShip(){
	if(this->isSunk){
		//if ship is already sunk, do something here
		return false;
	}
	else{
		//if ship is afloat, sink it here
		this->isSunk = true;
		return this->isSunk;
	}
}

bool Ship::getIsSunk(){
	return this->isSunk;
}

int Ship::getLength(){
	return this->length;
}

int main(int argc, char *argv[1]){
	int length;
	cout << "\nEnter ship length: "; cin >> length;
	Ship *test = new Ship(length);
	cout << "How long is this ship? " << test->getLength() << endl;
	cout << "Is this ship sunk? " << test->getIsSunk() << endl;
	cout << "Sink this ship! " << test->sinkShip() << endl;
	cout << "Is this ship sunk? " << test->getIsSunk() << endl << endl;

	return 0;
}