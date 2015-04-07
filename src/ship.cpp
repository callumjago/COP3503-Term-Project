#include "battleship_main.h"
//TODO store location of ship and figure out interaction with board.cpp
class Ship{
	public:
		bool sinkShip();	//attempts sinking the Ship (interp as setter method for state bool isSunk)
		bool getIsSunk();	//getter method for state bool isSunk
		int getLength();	//getter method for state int length
		Ship(int length);	//parametrized class constructor, input state int length

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

Ship::Ship(int length, str name, bool isHorizontal, int startY, int startX):length(length), status(NULL), isSunk(false){
	status = new int[length];
	this->startX = startX;
	this->startY = startY;
	this->name = name;	
	this->isHorizontal = isHorizontal;
	for(int i = 0; i < length; i++){	//Initializes status array to all 1s
		status[i] = 1;
	}
	//perhaps do something for state int* status
	if(length < 0){ this->length = 0; }
	else { this->length = length;}
}

void Ship::Initialize(board b) {
	if(isHorizontal) {
		for(int i = 0; i < length; i++) {
			b.values[(10*startY) + startX + i].status = 1; //not sure if 1 is correct value
		}
	}
	else {
		for(int i = 0; i < length; i++) {
			b.values[(10*startY) + startX + (10*i)].status = 1;
		}
	}
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
	for(int i = 0; i < length; i++) {
		if(status[i] != 1)
			return false;
	}
	return true;
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