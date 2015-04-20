#include "../include/computer.h"
#include "../include/display.h"
#include <string>
#include <stdlib.h>
#include <sstream>

//Represents a generated guess to hit a user's ship
int Computer::guess(){
	char let = 'A';
	int num = 1, counter = 0;
	desPos = "";
	int index_return;

	do{
		let = 'A' + (rand() % 10);
		num = rand() % 10 + 1;
		stringstream str;
		desPos = "";
		str << let << num;
		str >> desPos;
		if(++counter > 10000){ return -1; }		//Prevents an infinite loop, but allows ample guessing error if pickings are slim
	
	}while(isValidPos(desPos, 1, &index_return) == -1);

	//Guess is now a valid position (regardless of orientation because its ""length"" is 1
	num += (int)(let - 'A') * 10;				//Converts desPos into index value for board

	return num;

}

void Computer::printShips(){

	Display out = Display();
	char temp[5];
	for(int r = 0; r < 10; r++){
		for(int c = 0; c < 10; c++){
			int temp_int = board->getStatus((r * 10) + c + 1);
			stringstream ss; 
			ss << temp_int ;
			ss >> temp;
			out.push_to_second_display(temp);
			memset(&temp[0], 0, sizeof(temp));
		}
		out.push_to_second_display("\n");
	}
	for (int i = 0; i < 15; ++i)
	{
		out.push_to_second_display("-");
	}
	out.push_to_second_display("\n");
}

/*The formulate() function employs the computer's pseudorandom algorithm for picking a location on the board
to which a ship will be set, and checks accordingly with respect to chosen orientations, returning an int
corresponding to the chosen orientation for ship-setting; it also leaves desPos class state as this target
location. This need not be called by any other class but remains public for simplicity. */
int Computer::formulate(int length, int *index_return){
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
		orientation = isValidCompPos(desPos, length, &index_return);
		if(++counter > 10000){ return 0; }		//Prevents an infinite loop, but allows ample guessing error if pickings are slim
	
	}while(orientation == -1 || orientation == 0);

	return orientation;
}

void Computer::setCarrier(bool *addSuccess){
	int index = 0;
	int orientation = formulate(5, &index);
	char let = desPos.at(0);
	int num = (int)desPos.at(1) - 48;

	cout << index;

	if(num == 1 && desPos.length() == 3 && desPos.at(2) == '0'){
		num = 10;
	}

	if(orientation == 1){
		let -= 4;	//Readjusts position to act as "down" orientation with uppermost position put into initializer
		carrier = new Ship(5, "Carrier", false, let, num);
		carrier->Initialize(&board, index);
		*addSuccess = true;
	}
	else if(orientation == 2){
		carrier = new Ship(5, "Carrier", false, let, num);
		carrier->Initialize(&board, index);
		*addSuccess = true;
	}
	else if(orientation == 3){
		num -= 4;	//Readjusts position to act as "right" orientation with leftmost position put into initializer
		carrier = new Ship(5, "Carrier", true, let, num);
		carrier->Initialize(&board, index);
		*addSuccess = true;
	}
	else if(orientation == 4){
		carrier = new Ship(5, "Carrier", true, let, num);
		carrier->Initialize(&board, index);
		*addSuccess = true;
	}
	//printShips();
}

void Computer::setBattleship(bool *addSuccess){
	int index = 0;
	int orientation = formulate(4, &index);
	char let = desPos.at(0);
	int num = (int)desPos.at(1) - 48;

	if(num == 1 && desPos.length() == 3 && desPos.at(2) == '0'){
		num = 10;
	}

	if(orientation == 1){
		let -= 3;	//Readjusts position to act as "down" orientation with uppermost position put into initializer
		battleship = new Ship(4, "Battleship", false, let, num);
		battleship->Initialize(&board, index);
		*addSuccess = true;
	}
	else if(orientation == 2){
		battleship = new Ship(4, "Battleship", false, let, num);
		battleship->Initialize(&board, index);
		*addSuccess = true;
	}
	else if(orientation == 3){
		num -= 3;	//Readjusts position to act as "right" orientation with leftmost position put into initializer
		battleship = new Ship(4, "Battleship", true, let, num);
		battleship->Initialize(&board, index);
		*addSuccess = true;
	}
	else if(orientation == 4){
		battleship = new Ship(4, "Battleship", true, let, num);
		battleship->Initialize(&board, index);
		*addSuccess = true;
	}
	//printShips();
}

void Computer::setSubmarine(bool *addSuccess){
	int index = 0;
	int orientation = formulate(3, &index);
	char let = desPos.at(0);
	int num = (int)desPos.at(1) - 48;

	if(num == 1 && desPos.length() == 3 && desPos.at(2) == '0'){
		num = 10;
	}

	if(orientation == 1){
		let -= 2;	//Readjusts position to act as "down" orientation with uppermost position put into initializer
		submarine = new Ship(3, "Submarine", false, let, num);
		submarine->Initialize(&board, index);
		*addSuccess = true;
	}
	else if(orientation == 2){
		submarine = new Ship(3, "Submarine", false, let, num);
		submarine->Initialize(&board, index);
		*addSuccess = true;
	}
	else if(orientation == 3){
		num -= 2;	//Readjusts position to act as "right" orientation with leftmost position put into initializer
		submarine = new Ship(3, "Submarine", true, let, num);
		submarine->Initialize(&board, index);
		*addSuccess = true;
	}
	else if(orientation == 4){
		submarine = new Ship(3, "Submarine", true, let, num);
		submarine->Initialize(&board, index);
		*addSuccess = true;
	}
	//printShips();
}

void Computer::setCruiser(bool *addSuccess){
	int index = 0;
	int orientation = formulate(3, &index);
	char let = desPos.at(0);
	int num = (int)desPos.at(1) - 48;

	if(num == 1 && desPos.length() == 3 && desPos.at(2) == '0'){
		num = 10;
	}

	if(orientation == 1){
		let -= 2;	//Readjusts position to act as "down" orientation with uppermost position put into initializer
		cruiser = new Ship(3, "Cruiser", false, let, num);
		cruiser->Initialize(&board, index);
		*addSuccess = true;
	}
	else if(orientation == 2){
		cruiser = new Ship(3, "Cruiser", false, let, num);
		cruiser->Initialize(&board, index);
		*addSuccess = true;
	}
	else if(orientation == 3){
		num -= 2;	//Readjusts position to act as "right" orientation with leftmost position put into initializer
		cruiser = new Ship(3, "Cruiser", true, let, num);
		cruiser->Initialize(&board, index);
		*addSuccess = true;
	}
	else if(orientation == 4){
		cruiser = new Ship(3, "Cruiser", true, let, num);
		cruiser->Initialize(&board, index);
		*addSuccess = true;
	}
	//printShips();
}

void Computer::setDestroyer(bool *addSuccess){
	int index = 0;
	int orientation = formulate(2, &index);
	char let = desPos.at(0);
	int num = (int)desPos.at(1) - 48;
	if(num == 1 && desPos.length() == 3 && desPos.at(2) == '0'){
		num = 10;
	}

	if(orientation == 1){
		let -= 1;	//Readjusts position to act as "down" orientation with uppermost position put into initializer
		destroyer = new Ship(2, "Destroyer", false, let, num);
		destroyer->Initialize(&board, index);
		*addSuccess = true;
	}
	else if(orientation == 2){
		destroyer = new Ship(2, "Destroyer", false, let, num);
		destroyer->Initialize(&board, index);
		*addSuccess = true;
	}
	else if(orientation == 3){
		num -= 1;	//Readjusts position to act as "right" orientation with leftmost position put into initializer
		destroyer = new Ship(2, "Destroyer", true, let, num);
		destroyer->Initialize(&board, index);
		*addSuccess = true;
	}
	else if(orientation == 4){
		destroyer = new Ship(2, "Destroyer", true, let, num);
		destroyer->Initialize(&board, index);
		*addSuccess = true;
	}
	//printShips();
}

//Checks to see if the randomly generated desired ship position is a valid position to place the ships
int Computer::isValidCompPos(string desPos, int length, int **index_return){
	char let = desPos.at(0);
	int num = (int)desPos.at(1) - 48;

	if(num == 1 && desPos.length() == 3 && desPos.at(2) == '0'){
		num = 10;
	}

	char tempLet = 'A';
	int tempNum = 1;

	bool left = true, right = true, up = true, down = true;

	int ind = ((int)(let - 'A') * 10) + num;
	**index_return = ((int)(let - 'A') * 10) + num;
	int tempInd = 0;

	if(let < 'A' || let > 'J' || num < 1 || num > 10){
		//cout << "Error: invalid position choice." << endl;
		return -1;
	}

	if(board->getStatus(ind) != 0){
		//cout << "Error: ship already placed there." << endl;
		return -1;
	}

	if(let - length >= 'A'){					//Check for "up" orientation
		for(int i = 0; i <= length; i++){
			tempLet = let - i;
			tempNum = num;

			tempInd = ((tempLet - 'A') * 10) + tempNum;

			if(board->getStatus(ind) != 0){
				up = true;
			}
		}
	}

	if(let - length >= 'A'){					//Check if "up" orientation is possible
		tempLet = let;
		tempNum = num;
		
		for(int i = 0; i < length; i++){
			tempInd = ((tempLet-- - 'A') * 10) + tempNum;

			if(board->getStatus(tempInd) != 0){ up = false; }
		}
	}
	else{ up = false; }

	if(let + length <= 'J'){					//Check if "down" orientation is possible
		tempLet = let;
		tempNum = num;
		
		for(int i = 0; i < length; i++){
			tempInd = ((tempLet++ - 'A') * 10) + tempNum;

			if(board->getStatus(tempInd) != 0){ down = false; }
		}
	}
	else{ down = false; }

	if(num - length >= 1){						//Check if "left" orientation is possible
		tempLet = let;
		tempNum = num;
		
		for(int i = 0; i < length; i++){
			tempInd = ((tempLet - 'A') * 10) + tempNum--;

			if(board->getStatus(tempInd) != 0){ left = false; }
		}
	}
	else{ left = false; }

	if(num + length <= 10){						//Check if "right" orientation is possible
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
		//cout << "Error: no orientation options." << endl;		/*This is only an error when placing a ship, not when guessing a place to bomb*/
		return 0;
	}
	
	int randNum = rand() % 24;
	int m = 0;
	while(randNum >= 0){
		if(option[m++]){ randNum--; }
		if(m == 4){ m = 0; }
	}

	return m;	//-1 means invalid or error, 0 means no orientation options, 1 means "up", 2 means "down", 3 means "left", 4 means "right"
}
