#include "ship.h"



Ship::Ship(int length):length(length), status(0), isSunk(false){
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

int main(){

	//Testing the initialization of a ship of length 5.
	Ship test(5);

	cout << "How long is this ship? " << test.getLength() << endl;
	
	return 0;
}
