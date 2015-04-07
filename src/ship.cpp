#include <iostream>
#include "../include/board.h"
#include "../include/ship.h"
//TODO store location of ship and figure out interaction with board.cpp
//Status values: 0 - empty; 1 - not hit; 2 - hit

//x, and y specify top left most coordinate, ship then extends down if vertical, right if horizontal
Ship::Ship(int length, string name, bool isHorizontal, char startX, int startY):length(length), status(NULL), isSunk(false){
	status = new int[length];
	this->startX = 66 - startX;
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

void Ship::Initialize(Board b) {
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
	//Checks every element of status array, if any element is 1(not hit), return false
	for(int i = 0; i < length; i++) {
		if(status[i] == 1)
			return false;
	}
	return true;
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
