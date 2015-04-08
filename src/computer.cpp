#include "../include/computer.h"
#include <string>
#include <stdlib.h>
#include <sstream>

bool Computer::guess(){
	char let = 'A';
	int num = 1;
	desPos = "";

	do{
		let = 'A' + (rand() % 10);
		num = rand() % 10 + 1;
		stringstream str;
		desPos = "";
		str << let << num;
		str >> desPos;
	}while(isValidPos(desPos, 1) == -1);
	//guess is now a valid position (regardless of orientation because its ""length"" is 1
	{/*bomb the location aka make that guess*/}

	return false;
}

/*
the formulate() function employs the computer's pseudorandom algorithm for picking a location on the board
to which a ship will be set, and checks accordingly with respect to chosen orientations, returning an int
corresponding to the chosen orientation for ship-setting; it also leaves desPos class state as this target
location
*/
int Computer::formulate(int length){
	desPos = "";
	char let = 'A';
	int num = 1;
	stringstream str;
	int orientation = -1, counter = 0;

	do{
		let = 'A' + (rand() % 10);
		num = rand() % 10 + 1;
		str << let << num;
		str >> desPos;
		orientation = isValidPos(desPos, length);
		if(++counter > 10000){ return 0; }		//prevents an infinite loop, but allows ample guessing error if pickings are slim
	}while(orientation == -1 || orientation == 0);

	return orientation;
}

void Computer::setCarrier(bool *addSuccess){
	int orientation = formulate(5);
	char let = desPos.at(0);
	int num = (int)desPos.at(1) - 48;
	bool success = false;
	if(num == 1 && desPos.length() == 3 && desPos.at(2) == '0'){
		num = 10;
	}

	if(orientation == 1){
		let -= 4;	//readjusts position to act as "down" orientation with uppermost position put into initializer
		carrier = new Ship(5, "Carrier", false, let, num);
		success = true;
	}
	else if(orientation == 2){
		carrier = new Ship(5, "Carrier", false, let, num);
		success = true;
	}
	else if(orientation == 3){
		num -= 4;	//readjusts position to act as "right" orientation with leftmost position put into initializer
		carrier = new Ship(5, "Carrier", true, let, num);
		success = true;
	}
	else if(orientation == 4){
		carrier = new Ship(5, "Carrier", true, let, num);
		success = true;
	}
	addSuccess = &success;
}

void Computer::setBattleship(bool *addSuccess){
	int orientation = formulate(4);
	char let = desPos.at(0);
	int num = (int)desPos.at(1) - 48;
	bool success = false;
	if(num == 1 && desPos.length() == 3 && desPos.at(2) == '0'){
		num = 10;
	}

	if(orientation == 1){
		let -= 3;	//readjusts position to act as "down" orientation with uppermost position put into initializer
		carrier = new Ship(4, "Battleship", false, let, num);
		success = true;
	}
	else if(orientation == 2){
		carrier = new Ship(4, "Battleship", false, let, num);
		success = true;
	}
	else if(orientation == 3){
		num -= 3;	//readjusts position to act as "right" orientation with leftmost position put into initializer
		carrier = new Ship(4, "Battleship", true, let, num);
		success = true;
	}
	else if(orientation == 4){
		carrier = new Ship(4, "Battleship", true, let, num);
		success = true;
	}
	addSuccess = &success;
}

void Computer::setSubmarine(bool *addSuccess){
	int orientation = formulate(3);
	char let = desPos.at(0);
	int num = (int)desPos.at(1) - 48;
	bool success = false;
	if(num == 1 && desPos.length() == 3 && desPos.at(2) == '0'){
		num = 10;
	}

	if(orientation == 1){
		let -= 2;	//readjusts position to act as "down" orientation with uppermost position put into initializer
		carrier = new Ship(3, "Submarine", false, let, num);
		success = true;
	}
	else if(orientation == 2){
		carrier = new Ship(3, "Submarine", false, let, num);
		success = true;
	}
	else if(orientation == 3){
		num -= 2;	//readjusts position to act as "right" orientation with leftmost position put into initializer
		carrier = new Ship(3, "Submarine", true, let, num);
		success = true;
	}
	else if(orientation == 4){
		carrier = new Ship(3, "Submarine", true, let, num);
		success = true;
	}
	addSuccess = &success;
}

void Computer::setCruiser(bool *addSuccess){
	int orientation = formulate(3);
	char let = desPos.at(0);
	int num = (int)desPos.at(1) - 48;
	bool success = false;
	if(num == 1 && desPos.length() == 3 && desPos.at(2) == '0'){
		num = 10;
	}

	if(orientation == 1){
		let -= 2;	//readjusts position to act as "down" orientation with uppermost position put into initializer
		carrier = new Ship(3, "Cruiser", false, let, num);
		success = true;
	}
	else if(orientation == 2){
		carrier = new Ship(3, "Cruiser", false, let, num);
		success = true;
	}
	else if(orientation == 3){
		num -= 2;	//readjusts position to act as "right" orientation with leftmost position put into initializer
		carrier = new Ship(3, "Cruiser", true, let, num);
		success = true;
	}
	else if(orientation == 4){
		carrier = new Ship(3, "Cruiser", true, let, num);
		success = true;
	}
	addSuccess = &success;
}

void Computer::setDestroyer(bool *addSuccess){
	int orientation = formulate(2);
	char let = desPos.at(0);
	int num = (int)desPos.at(1) - 48;
	bool success = false;
	if(num == 1 && desPos.length() == 3 && desPos.at(2) == '0'){
		num = 10;
	}

	if(orientation == 1){
		let -= 1;	//readjusts position to act as "down" orientation with uppermost position put into initializer
		carrier = new Ship(2, "Destroyer", false, let, num);
		success = true;
	}
	else if(orientation == 2){
		carrier = new Ship(2, "Destroyer", false, let, num);
		success = true;
	}
	else if(orientation == 3){
		num -= 1;	//readjusts position to act as "right" orientation with leftmost position put into initializer
		carrier = new Ship(2, "Destroyer", true, let, num);
		success = true;
	}
	else if(orientation == 4){
		carrier = new Ship(2, "Destroyer", true, let, num);
		success = true;
	}
	addSuccess = &success;
}

int Computer::isValidPos(string desPos, int length){
	char let = desPos.at(0);
	int num = (int)desPos.at(1) - 48;
	if(num == 1 && desPos.length() == 3 && desPos.at(2) == '0'){
		num = 10;
	}

	char tempLet = 'A';
	int tempNum = 1;

	bool left = true, right = true, up = true, down = true;

	int ind = ((int)(let - 'A') * 10) + num;
	int tempInd = 0;

	if(let < 'A' || let > 'J' || num < 1 || num > 10){
		//cout << "Error: invalid position choice." << endl;
		return -1;
	}

	if(board->getStatus(ind) != 0){
		//cout << "Error: ship already placed there." << endl;
		return -1;
	}

	if(let - length >= 'A'){					//check for "up" orientation
		for(int i = 0; i <= length; i++){
			tempLet = let - i;
			tempNum = num;

			tempInd = ((tempLet - 'A') * 10) + tempNum;

			if(board->getStatus(ind) != 0){
				up = true;
			}
		}
	}

	if(let - length >= 'A'){					//check if "up" orientation is possible
		tempLet = let;
		tempNum = num;
		for(int i = 0; i < length; i++){
			tempInd = ((tempLet-- - 'A') * 10) + tempNum;

			if(board->getStatus(tempInd) != 0){ up = false; }
		}
	}
	else{ up = false; }

	if(let + length <= 'J'){					//check if "down" orientation is possible
		tempLet = let;
		tempNum = num;
		for(int i = 0; i < length; i++){
			tempInd = ((tempLet++ - 'A') * 10) + tempNum;

			if(board->getStatus(tempInd) != 0){ down = false; }
		}
	}
	else{ down = false; }

	if(num - length >= 1){					//check if "left" orientation is possible
		tempLet = let;
		tempNum = num;
		for(int i = 0; i < length; i++){
			tempInd = ((tempLet - 'A') * 10) + tempNum--;

			if(board->getStatus(tempInd) != 0){ left = false; }
		}
	}
	else{ left = false; }

	if(num + length <= 10){					//check if "right" orientation is possible
		tempLet = let;
		tempNum = num;
		for(int i = 0; i < length; i++){
			tempInd = ((tempLet - 'A') * 10) + tempNum++;

			if(board->getStatus(tempInd) != 0){ right = false; }
		}
	}
	else{ right = false; }

	bool *option = new bool[4];
	option[0] = up;
	option[1] = down;
	option[2] = left;
	option[3] = right;

	int sum = 0;
	for(int i = 0; i < 4; i++){ if(option[i]){ sum++; } }

	if(sum == 0){
		//cout << "Error: no orientation options." << endl;		/*this is only an error when placing a ship, not when guessing a place to bomb*/
		return 0;
	}
	
	int randNum = rand() % 24;
	int m = 0;
	while(randNum >= 0){
		if(option[m++]){ randNum--; }
		if(m == 4){ m = 0; }
	}

	return m;	// -1 means invalid or error, 0 means no orientation options, 1 means "up", 2 means "down", 3 means "left", 4 means "right"
}