#include "../include/user.h"
#include <iostream>


/*This function is used for the user to input a guess for a location on the board to hit. This 
function will return an index value that corresponds to the array value of the desired location 
on the board. This function is to be called using the "Turn" class. 
*/
int User::guess(){

	string guess = "";
	cout << "Enter your guess: ";
	cin >> guess;

	if(guess.length() < 1 || guess.length() > 3){
		return -1;
	}

	char letter = guess.at(0);
	int digit = guess.at(1);
	if(digit == 1 && (int)guess.at(2) == 0){
		digit = 10;
	}

	int index = ((letter - 'A') * 10) + digit; //Determines the index of the position in the board.
	
	return index;
};

//This function is used to see if the desired position of the ship is valid 
// -1 means invalid or error, 0 means "up", 1 means "down", 2 means "left", 3 means "right"
int User::isValidPos(string desPos, int length){
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
	int tempIndex = 0;


	if(letter >= 'A' && letter <= 'J' && digit >= 1 && digit <= 10){
		if(board->getStatus(index) == 0){

			//Checks to see if down is possible.
			if(letter + length >= 'J'){
				for(int i = 1; i <= length; i++){
					tempLetter = letter + i;
					tempDigit = digit;

					tempIndex = ((tempLetter - 'A') * 10) + tempDigit;

					if(board->getStatus(index) == 0){
					}
					else{
						down = false;
					}
				}

			}

			//Checks to see if right is possible.
			if(digit + length <= 10){
				for(int i = 1; i <= length; i++){
					tempLetter = letter;
					tempDigit = digit + i;

					tempIndex = ((tempLetter - 'A') * 10) + tempDigit;

					if(board->getStatus(index) == 0){
					}
					else{
						right = false;
					}
				}

			}

			//Given the possibilities, asks the user which direction to choose.
			if(!right && !down){
				//cout << "Unable to place a ship of this length there.";
				// Represents that the placement there is unavailable.
			}
			else if(right && down){
				cout << "\nChoose to orientate the ship right (R) or down (D): ";
				cin >> direction;

				if(direction.compare("R") == 0){
					choice = 3;
				}
				else if(direction.compare("D") == 0){
					choice = 1;
				}
				else{
					// Represents that the choice of right/down is invalid.
					return -1;
				}
			/*else{
				do{
					cout << "Invalid choice. Choose again: ";
					cin >> direction;
					if(direction.compare("right") == 0){
						choice = 3;
					}
					else if(direction.compare("down") == 0){
						choice = 1;
					}
				} while (direction.compare("down") != 0 && direction.compare("right") != 0);
			}*/
			}
			else if(down){
				choice = 1;
			}
			else if(right){
				choice = 3; 
			}
		}
		else{
			// Keeps choice as -1, invalid position.
		}
	}
	else{
		//cout << "Invalid position choice.";
		// Represents invalid position choice.
	}

	
	return choice;	

	// -1 means invalid or error, 0 means "up", 1 means "down", 2 means "left", 3 means "right"
};

void User::setCarrier(bool *addSuccess){
	//std::cout << carrier->getIsSunk();

	string desPos = "";

	cout << "\nEnter the desired position of your carrier: ";
	cin >> desPos;

	choice = isValidPos(desPos, 5);

	if(choice == 1){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(5, "Carrier", false, desPos.at(0), 10);
			carrier->Initialize(board);
			*addSuccess= true;
		}
		else if(desPos.length() == 2){ 
			carrier = new Ship(5, "Carrier", false, desPos.at(0), (int)(desPos.at(1) - 48));
			carrier->Initialize(board);
			*addSuccess= true;
		}
	}
	
	else if(choice == 3){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(5, "Carrier", true, desPos.at(0), 10);
			carrier->Initialize(board);
			*addSuccess= true;
		}
		else{
			carrier = new Ship(5, "Carrier", true, desPos.at(0), (int)(desPos.at(1) - 48));
			carrier->Initialize(board);
			*addSuccess= true;
		}
	}
	else{
		*addSuccess = false;
	}


	for(int i = 0; i < 10; i++){

		for(int i = 0; i < 10; i++){
			cout << getBoard().getStatus((i * 10) + i) << " ";
		}
		cout << "\n";
	}


}
void User::setBattleship(bool *addSuccess){
	//std::cout << battleship->getIsSunk();

	string desPos = "";

	cout << "\nEnter the desired position of your carrier: ";
	cin >> desPos;

	choice = isValidPos(desPos, 4);

	if(choice == 1){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(4, "Carrier", false, desPos.at(0), 10);
			carrier->Initialize(board);
			*addSuccess= true;
		}
		else if(desPos.length() == 2){ 
			carrier = new Ship(4, "Carrier", false, desPos.at(0), (int)(desPos.at(1) - 48));
			carrier->Initialize(board);
			*addSuccess= true;
		}
	}
	
	else if(choice == 3){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(4, "Carrier", true, desPos.at(0), 10);
			carrier->Initialize(board);
			*addSuccess= true;
		}
		else{
			carrier = new Ship(4, "Carrier", true, desPos.at(0), (int)(desPos.at(1) - 48));
			carrier->Initialize(board);
			*addSuccess= true;
		}
	}
	else{
		*addSuccess = false;
	}


	for(int i = 0; i < 10; i++){

		for(int i = 0; i < 10; i++){
			cout << getBoard().getStatus((i * 10) + i) << " ";
		}
		cout << "\n";
	}
}
void User::setSubmarine(bool *addSuccess){
	//std::cout << submarine->getIsSunk();

	string desPos = "";

	cout << "\nEnter the desired position of your carrier: ";
	cin >> desPos;

	choice = isValidPos(desPos, 3);

	if(choice == 1){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(3, "Carrier", false, desPos.at(0), 10);
			carrier->Initialize(board);
			*addSuccess= true;
		}
		else if(desPos.length() == 2){ 
			carrier = new Ship(3, "Carrier", false, desPos.at(0), (int)(desPos.at(1) - 48));
			carrier->Initialize(board);
			*addSuccess= true;
		}
	}
	
	else if(choice == 3){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(3, "Carrier", true, desPos.at(0), 10);
			carrier->Initialize(board);
			*addSuccess= true;
		}
		else{
			carrier = new Ship(3, "Carrier", true, desPos.at(0), (int)(desPos.at(1) - 48));
			carrier->Initialize(board);
			*addSuccess= true;
		}
	}
	else{
		*addSuccess = false;
	}


	for(int i = 0; i < 10; i++){

		for(int i = 0; i < 10; i++){
			cout << getBoard().getStatus((i * 10) + i) << " ";
		}
		cout << "\n";
	}
}
void User::setCruiser(bool *addSuccess){
	//std::cout << cruiser->getIsSunk();

	string desPos = "";

	cout << "\nEnter the desired position of your carrier: ";
	cin >> desPos;

	choice = isValidPos(desPos, 3);

	if(choice == 1){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(3, "Carrier", false, desPos.at(0), 10);
			carrier->Initialize(board);
			*addSuccess= true;
		}
		else if(desPos.length() == 2){ 
			carrier = new Ship(3, "Carrier", false, desPos.at(0), (int)(desPos.at(1) - 48));
			carrier->Initialize(board);
			*addSuccess= true;
		}
	}
	
	else if(choice == 3){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(3, "Carrier", true, desPos.at(0), 10);
			carrier->Initialize(board);
			*addSuccess= true;
		}
		else{
			carrier = new Ship(3, "Carrier", true, desPos.at(0), (int)(desPos.at(1) - 48));
			carrier->Initialize(board);
			*addSuccess= true;
		}
	}
	else{
		*addSuccess = false;
	}


	for(int i = 0; i < 10; i++){

		for(int i = 0; i < 10; i++){
			cout << getBoard().getStatus((i * 10) + i) << " ";
		}
		cout << "\n";
	}
}
void User::setDestroyer(bool *addSuccess){
	//std::cout << destroyer->getIsSunk();

	string desPos = "";

	cout << "\nEnter the desired position of your carrier: ";
	cin >> desPos;

	choice = isValidPos(desPos, 2);

	if(choice == 1){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(2, "Carrier", false, desPos.at(0), 10);
			carrier->Initialize(board);
			*addSuccess= true;
		}
		else if(desPos.length() == 2){ 
			carrier = new Ship(2, "Carrier", false, desPos.at(0), (int)(desPos.at(1) - 48));
			carrier->Initialize(board);
			*addSuccess= true;
		}
	}
	
	else if(choice == 3){
		if(desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(2, "Carrier", true, desPos.at(0), 10);
			carrier->Initialize(board);
			*addSuccess= true;
		}
		else{
			carrier = new Ship(2, "Carrier", true, desPos.at(0), (int)(desPos.at(1) - 48));
			carrier->Initialize(board);
			*addSuccess= true;
		}
	}
	else{
		*addSuccess = false;
	}


	for(int i = 0; i < 10; i++){

		for(int i = 0; i < 10; i++){
			cout << getBoard().getStatus((i * 10) + i) << " ";
		}
		cout << "\n";
	}
}

