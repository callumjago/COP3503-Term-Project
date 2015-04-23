#include "../include/user.h"
#include "../include/display.h"
#include <iostream>


/*This function is used for the user to input a guess for a location on the board to hit. This 
function will return an index value that corresponds to the array value of the desired location 
on the board. This function is to be called using the "Turn" class. 
*/
int User::guess(){

	string guess = "";
	cout << "Enter your guess: ";
	bool isValid = false;

	

	do{
		cin >> guess;
		if(guess.length() > 2 || guess.length() > 3){
			cout << "\nInvalid guess. Try again:\n";	
		}
		else if(guess.at(0) < 'A' || guess.at(0) > 'Z'){
			cout << "\nInvalid guess. Try again:\n";
		}
		else if(guess.at(1) < '1' || guess.at(1) > '9'){
			cout << "\nInvalid guess. Try again:\n";
		}
		else if(guess.length() == 3 && guess.at(1) != '1' && guess.at(2) != '0'){
			cout << "\nInvalid guess. Try again:\n";
		}
		else{
			isValid = true;
		}
	}
	while(!isValid);

	if(guess.length() < 1 || guess.length() > 3){
		return -1;
	}

	char letter = guess.at(0);
	int digit = guess.at(1);

	if(digit == 1 && (int)guess.at(2) == 0){
		digit = 10;
	}

	int index = (((letter - 'A') * 10) + digit) - 48; //Determines the index of the position in the board.
	
	return index;
};

//This function is used to see if the desired position of the ship is valid 
// -1 means invalid or error, 0 means "up", 1 means "down", 2 means "left", 3 means "right"
int User::isValidPos(string desPos, int length, int *index_return){

	string direction = ""; //Can be either up, down, or right.
	
	bool right = true;
	bool down = true;

	if(desPos.length() < 1 || desPos.length() > 3){
		return -1;
	}

	char letter = desPos.at(0);
	int digit = (int)desPos.at(1) - 48;

	if(desPos.length() == 3 && digit == 1 && desPos.at(2) == '0'){
		digit = 10;
	}
	else if(desPos.length() == 3 && digit != 1 && desPos.at(2) != '0'){
		return -1;
	}

	char tempLetter = 'A';
	int tempDigit = 1;

	int index = ((int)(letter - 'A') * 10) + digit; //Determines the index of the position in the board.
	*index_return = ((int)(letter - 'A') * 10) + digit;
	int tempIndex = 0;

	if(letter >= 'A' && letter <= 'J' && digit >= 1 && digit <= 10){
		//Represents if the position desired already has a ship there.
		if(board->getStatus(index) == 0){

			//Checks to see if down is possible.
			if(letter + length <= 'J'){
				for(int i = 1; i <= length; i++){
					tempLetter = letter + i;
					tempDigit = digit;

					tempIndex = ((tempLetter - 'A') * 10) + tempDigit;

					if(board->getStatus(tempIndex) == 0){
					}
					else{
						down = false;
					}
				}
			}
			else{
				down = false;
			}

			//Checks to see if right is possible.
			if(digit + length <= 10){
				for(int i = 1; i <= length; i++){
					tempLetter = letter;
					tempDigit = digit + i;

					tempIndex = ((tempLetter - 'A') * 10) + tempDigit;

					if(board->getStatus(tempIndex) == 0){
					}
					else{
						right = false;
					}
				}
			}
			else{
				right = false;
			}

			//Given the possibilities, asks the user which direction to choose.
			if(!right && !down){

				cout << "Unable to place a ship of this length there.";
				//Represents that the placement there is unavailable.
				return -1;
			}
			else if(right && down){
				cout << "Choose to orientate the ship right (R) or down (D): ";
				cin >> direction;
				while(!((direction.compare("R") == 0) || (direction.compare("D") == 0))){
					cout << "Incorrect Entry\n";
					cout << "Choose to orientate the ship right (R) or down (D): ";
					direction = "";
					cin >> direction;
				}
				if(direction.compare("R") == 0){
						choice = 3;
						cout << "Placing ship right.";
					}
				if(direction.compare("D") == 0){
						choice = 1;
						cout << "Placing ship down.";
				}
				direction = "";
			}
			else if(down){
				choice = 1;
				cout << "Placing ship down.";
			}
			else if(right){
				choice = 3; 
				cout << "Placing ship right.";
			}
		}
		else{
			return -1;
		}
	}
	else{
		cout << "Invalid position choice.";
		//Represents invalid position choice.
		return -1;
	}

	return choice;	
	//-1 means invalid or error, 0 means "up", 1 means "down", 2 means "left", 3 means "right"
};


//Prints the ships
void User::printShips(){

	Display out = Display();
	char temp[5];
	for(int r = 0; r < 10; r++){
		for(int c = 0; c < 10; c++){
			int temp_int = board->getStatus((r * 10) + c + 1);
			stringstream ss; 
			ss << temp_int ;
			ss >> temp;
			//out.push_to_first_display(temp);
			cout << temp << " ";
			memset(&temp[0], 0, sizeof(temp));
		}
		//out.push_to_first_display("\n");
		cout << "\n";
	}
	for (int i = 0; i < 15; ++i)
	{
		//out.push_to_first_display("-");
		cout << "-";
	}
	//out.push_to_first_display("\n");
	cout << "\n";
}

void User::setCarrier(bool *addSuccess){
	//std::cout << carrier->getIsSunk();

	string desPos = "";

	cout << "Enter the desired position of your carrier: ";
	while(!(cin >> desPos)){
		cin.clear(); // LINE 9
		cout << "Please enter a valid poisition.\n";
	}

	int index;
	choice = isValidPos(desPos, 5, &index);

	cout << (int)(desPos.at(0) - 65);
	cout << (int)(desPos.at(1) - 48);

	if(choice == 1){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(5, "Carrier", false, desPos.at(0), 10);
			carrier->Initialize(&board, index);
			*addSuccess= true;
		}
		else if(desPos.length() == 2){ 
			carrier = new Ship(5, "Carrier", false, desPos.at(0), (int)(desPos.at(1) - 48));
			carrier->Initialize(&board, index);
			*addSuccess= true;
		}
	}
	else if(choice == 3){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(5, "Carrier", true, desPos.at(0), 10);
			carrier->Initialize(&board, index);
			*addSuccess= true;
		}
		else{
			carrier = new Ship(5, "Carrier", true, desPos.at(0), (int)(desPos.at(1) - 48));
			carrier->Initialize(&board, index);
			*addSuccess= true;
		}
	}
	else{
		*addSuccess = false;
	}
	//printShips();
}

void User::setBattleship(bool *addSuccess){
	//std::cout << battleship->getIsSunk();

	string desPos = "";

	cout << "\nEnter the desired position of your Battleship: ";
	while(!(cin >> desPos)){
		cin.clear(); // LINE 9
		cout << "Please enter a valid poisition.\n";
	}
	int index;
	choice = isValidPos(desPos, 4, &index);

	if(choice == 1){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			battleship = new Ship(4, "Battleship", false, desPos.at(0), 10);
			battleship->Initialize(&board, index);
			*addSuccess= true;
		}
		else if(desPos.length() == 2){ 
			battleship = new Ship(4, "Battleship", false, desPos.at(0), (int)(desPos.at(1) - 48));
			battleship->Initialize(&board, index);
			*addSuccess= true;
		}
	}
	else if(choice == 3){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			battleship = new Ship(4, "Battleship", true, desPos.at(0), 10);
			battleship->Initialize(&board, index);
			*addSuccess= true;
		}
		else{
			battleship = new Ship(4, "Battleship", true, desPos.at(0), (int)(desPos.at(1) - 48));
			battleship->Initialize(&board, index);
			*addSuccess= true;
		}
	}
	else{
		*addSuccess = false;
	}
	//printShips();
}

void User::setSubmarine(bool *addSuccess){
	//std::cout << submarine->getIsSunk();

	string desPos = "";

	cout << "\nEnter the desired position of your submarine: ";
	while(!(cin >> desPos)){
		cin.clear(); // LINE 9
		cout << "Please enter a valid poisition.\n";
	}

	int index;
	choice = isValidPos(desPos, 3, &index);

	if(choice == 1){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			submarine = new Ship(3, "Submarine", false, desPos.at(0), 10);
			submarine->Initialize(&board, index);
			*addSuccess= true;
		}
		else if(desPos.length() == 2){ 
			submarine = new Ship(3, "Submarine", false, desPos.at(0), (int)(desPos.at(1) - 48));
			submarine->Initialize(&board, index);
			*addSuccess= true;
		}
	}
	
	else if(choice == 3){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			submarine = new Ship(3, "Submarine", true, desPos.at(0), 10);
			submarine->Initialize(&board, index);
			*addSuccess= true;
		}
		else{
			submarine = new Ship(3, "Submarine", true, desPos.at(0), (int)(desPos.at(1) - 48));
			submarine->Initialize(&board, index);
			*addSuccess= true;
		}
	}
	else{
		*addSuccess = false;
	}
	//printShips();
}

void User::setCruiser(bool *addSuccess){
	//std::cout << cruiser->getIsSunk();

	string desPos = "";

	cout << "\nEnter the desired position of your cruiser: ";
	while(!(cin >> desPos)){
		cin.clear(); // LINE 9
		cout << "Please enter a valid poisition.\n";
	}

	int index;
	choice = isValidPos(desPos, 3, &index);

	if(choice == 1){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			cruiser = new Ship(3, "Cruiser", false, desPos.at(0), 10);
			cruiser->Initialize(&board, index);
			*addSuccess= true;
		}
		else if(desPos.length() == 2){ 
			cruiser = new Ship(3, "Cruiser", false, desPos.at(0), (int)(desPos.at(1) - 48));
			cruiser->Initialize(&board, index);
			*addSuccess= true;
		}
	}
	
	else if(choice == 3){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			cruiser = new Ship(3, "Cruiser", true, desPos.at(0), 10);
			cruiser->Initialize(&board, index);
			*addSuccess= true;
		}
		else{
			cruiser = new Ship(3, "Cruiser", true, desPos.at(0), (int)(desPos.at(1) - 48));
			cruiser->Initialize(&board, index);
			*addSuccess= true;
		}
	}
	else{
		*addSuccess = false;
	}
	//printShips();
}

void User::setDestroyer(bool *addSuccess){
	//std::cout << destroyer->getIsSunk();

	string desPos = "";

	cout << "\nEnter the desired position of your destroyer: ";
	while(!(cin >> desPos)){
		cin.clear(); // LINE 9
		cout << "Please enter a valid poisition.\n";
	}

	int index;
	choice = isValidPos(desPos, 2, &index);

	if(choice == 1){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			destroyer = new Ship(2, "Destroyer", false, desPos.at(0), 10);
			destroyer->Initialize(&board, index);
			*addSuccess= true;
		}
		else if(desPos.length() == 2){ 
			destroyer = new Ship(2, "Destroyer", false, desPos.at(0), (int)(desPos.at(1) - 48));
			destroyer->Initialize(&board, index);
			*addSuccess= true;
		}
	}
	
	else if(choice == 3){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			destroyer = new Ship(2, "Destroyer", true, desPos.at(0), 10);
			destroyer->Initialize(&board, index);
			*addSuccess= true;
		}
		else{
			destroyer = new Ship(2, "Destroyer", true, desPos.at(0), (int)(desPos.at(1) - 48));
			destroyer->Initialize(&board, index);
			*addSuccess= true;
		}
	}
	else{
		*addSuccess = false;
	}
	//printShips();
}

