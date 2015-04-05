#include "../include/ship.h"



bool Ship::sinkShip(){
	if(this->isSunk){
		//if ship is already sunk, do something here
		return false;
	}
	else{
		//if ship is afloat, sink it here
		this->isSunk = true;

		std::cout << "SINKING SHIP\n";
		return this->isSunk;
	}
}

bool Ship::getIsSunk(){
	return this->isSunk;
}

int Ship::getLength(){
	return this->length;
}


