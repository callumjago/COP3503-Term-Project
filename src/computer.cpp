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

bool Computer::setShip(){
	string desPos = "";
	char let = 'A';
	int num = 1;
	stringstream str;
	int orientation = -1;

	do{									//manages placement for the carrier
		let = 'A' + (rand() % 10);
		num = rand() % 10 + 1;
		str << let << num;
		str >> desPos;
		orientation = isValidPos(desPos, 5);
	}while(orientation == -1 || orientation == 0);
	//orientation is now inequal to -1 and 0
	{/*set and orient the carrier*/}

	do{									//manages placement for the battleship
		let = 'A' + (rand() % 10);
		num = rand() % 10 + 1;
		str << let << num;
		str >> desPos;
		orientation = isValidPos(desPos, 4);
	}while(orientation == -1 || orientation == 0);
	//orientation is now inequal to -1 and 0
	{/*set and orient the battleship*/}

	do{									//manages placement for the submarine
		let = 'A' + (rand() % 10);
		num = rand() % 10 + 1;
		str << let << num;
		str >> desPos;
		orientation = isValidPos(desPos, 3);
	}while(orientation == -1 || orientation == 0);
	//orientation is now inequal to -1 and 0
	{/*set and orient the submarine*/}

	do{									//manages placement for the cruiser
		let = 'A' + (rand() % 10);
		num = rand() % 10 + 1;
		str << let << num;
		str >> desPos;
		orientation = isValidPos(desPos, 3);
	}while(orientation == -1 || orientation == 0);
	//orientation is now inequal to -1 and 0
	{/*set and orient the cruiser*/}

	do{									//manages placements for the destroyer
		let = 'A' + (rand() % 10);
		num = rand() % 10 + 1;
		str << let << num;
		str >> desPos;
		orientation = isValidPos(desPos, 5);
	}while(orientation == -1 || orientation == 0);
	//orientation is now inequal to -1 and 0
	{/*set and orient the destroyer*/}
	
	return true;
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