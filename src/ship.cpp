#include <iostream>
#include "../include/board.h"
#include "../include/ship.h"
//TODO store location of ship and figure out interaction with board.cpp
//Status values: 0 - empty; 1 - not hit; 2 - hit

//x, and y specify top left most coordinate, ship then extends down if vertical, right if horizontal


//Initializes the ship by changing the board status to 1 for each part of the ship
void Ship::Initialize(Board **b, int index) {

	//int ind = (((int)getStartX() - 65) * 10) + getStartY();
	
	if(getIsHorizontal()) {
		for(int i = index; i < index + getLength(); i++) {
			(*b)->setStatus(i, 1); //sets status in sequential tiles to 1 for not hit
		}
		//(*b)->setStatus(index, 1);
	}
	else {
		for(int i = index; i <= index + (getLength()*10); i+=10) {
			(*b)->setStatus(i, 1); //Sets status in vertically sequetial tiles to 1 for not hit
		}
		//(*b)->setStatus(index, 1);
	}
	
}

//Sinks the ship if not already sunk
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

//Returns true if the ship has been sunk, false otherwise
bool Ship::getIsSunk(Board *board){
	//Checks every element of status array, if any element is not 2(hit), return false
	bool sunk = true;

	if(isHorizontal) {
		for(int i = 0; i < length; i++) {
			if(board->getStatus((10*startY) + startX + i) != 2) {
				sunk = false;
			}
		}
	}
	else {
		for(int i = 0; i < length; i++) {
			if(board->getStatus((10*startY) + startX + (10*i)) != 2) {
				sunk = false;
			}
		}
	}
	return sunk;
}

int Ship::getLength(){
	//Returns length
	return this->length;
}

/*
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
*/
