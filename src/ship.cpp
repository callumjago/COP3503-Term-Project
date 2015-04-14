#include <iostream>
#include "../include/board.h"
#include "../include/ship.h"
//TODO store location of ship and figure out interaction with board.cpp
//Status values: 0 - empty; 1 - not hit; 2 - hit

//x, and y specify top left most coordinate, ship then extends down if vertical, right if horizontal


void Ship::Initialize(Board* b) {
	if(isHorizontal) {
		for(int i = 0; i < length; i++) {
			//sets status in sequential tiles to 1 for not hit
			b->setStatus((10*startY) + startX + i, 1)
		}
	}
	else {
		for(int i = 0; i < length; i++) {
			//Sets status in vertically sequetial tiles to 1 for not hit
			b->setStatus((10*startY) + startX + (10*i), 1)
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

bool Ship::getIsSunk(Board* b){
	//Checks every element of status array, if any element is 1(not hit), return false
	int temp
	bool sunk = true;
	if(isHorizontal) {
		for(int i = 0; i < length; i++) {
			temp = b->getStatus((10*startY) + startX + i);
			if(temp == 1) {
				sunk = false;
			}
			
		}
	}
	else {
		for(int i = 0; i < length; i++) {
			temp = b->getStatus((10*startY) + startX + (10*i))
			if(temp == 1) {
				sunk = false;
			}
		}
	}
	return sunk;
}

int Ship::getLength(){
	//returns length
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
