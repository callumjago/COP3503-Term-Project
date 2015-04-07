#include "../include/user.h"


bool User::guess(){

	string guess = "";
	cout << "Enter your guess: ";
	cin >> guess;


	return false;
};

/*bool User::setShip(){

	string desPose = "";

	cout << "Enter the desired position of your carrier: ";
	cin >> desPose;

	if(isValidPos(desPose, 2) >= 0){
		//Set ship based on direction and coordinates.
	}
	else{
		do{
			"Invalid position, enter a different position: ";
			cin >> desPose;
			if(isValidPos(desPose, 2) >= 0){
				//Set ship based on direction and coordinates.
			}
		} while (isValidPos(desPose, 2) < 0);
	}


	cout << "Enter the desired position of your battleship: ";
	cin >> desPose;

	if(isValidPos(desPose, 3) >= 0){
		//Set ship based on direction and coordinates.
	}
	else{
		do{
			"Invalid position, enter a different position: ";
			cin >> desPose;
			if(isValidPos(desPose, 3) >= 0){
				//Set ship based on direction and coordinates.
			}
		} while (isValidPos(desPose, 3) < 0);
	}


	cout << "Enter the desired position of your submarine: ";
	cin >> desPose;

	if(isValidPos(desPose, 3) >= 0){
		//Set ship based on direction and coordinates.
	}
	else{
		do{
			"Invalid position, enter a different position: ";
			cin >> desPose;
			if(isValidPos(desPose, 3) >= 0){
				//Set ship based on direction and coordinates.
			}
		} while (isValidPos(desPose, 3) < 0);
	}


	cout << "Enter the desired position of your cruiser: ";
	cin >> desPose;

	if(isValidPos(desPose, 4) >= 0){
		//Set ship based on direction and coordinates.
	}
	else{
		do{
			"Invalid position, enter a different position: ";
			cin >> desPose;
			if(isValidPos(desPose, 4) >= 0){
				//Set ship based on direction and coordinates.
			}
		} while (isValidPos(desPose, 4) < 0);
	}


	cout << "Enter the desired position of your destroyer: ";
	cin >> desPose;

	if(isValidPos(desPose, 5) >= 0){
		//Set ship based on direction and coordinates.
	}
	else{
		do{
			"Invalid position, enter a different position: ";
			cin >> desPose;
			if(isValidPos(desPose, 5) >= 0){
				//Set ship based on direction and coordinates.
			}
		} while (isValidPos(desPose, 5) < 0);
	}


	return false;
};*/


int User::isValidPos(string desPos, int length){
	string direction = ""; //Can be either up, down, or right.
	
	bool right = true;
	bool down = true;


	char letter = desPos.at(0);
	int digit = desPos.at(1);
	if(digit == 1 && (int)desPos.at(2) == 0){
		digit = 10;
	}

	char tempLetter = 'A';
	int tempDigit = 1;

	int index = ((letter - 'A') * 10) + digit; //Determines the index of the position in the board.
	int tempIndex = 0;

	int choice = -1;


	if(letter >= 'A' && letter <= 'J' && digit >= 1 && digit <= 10){
	}
	else{
		cout << "Invalid position choice.";
	}

	
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
			cout << "Unable to place a ship of this length there.";
		}
		else if(right && down){
			cout << "Choose to orientate the ship right or down: ";
			cin >> direction;
			if(direction.compare("right") == 0){
				choice = 3;
			}
			else if(direction.compare("down") == 0){
				choice = 1;
			}
			else{
				do{
					"Invalid choice. Choose again: ";
					cin >> direction; = 0;
					}
					else if(direction.compare("right") == 0){
						choice = 3;
					}
					else if(direction.compare("down") == 0){
						choice = 1;
					}
				} while (direction.compare("down") != 0 && direction.compare("right") != 0);
			}
		}
		else if(down){
			choice = 1;
		}
		else if(right){
			choice = 3;
		}

	}
	else{
		cout << "Ship already placed there.";
	}

	return choice;	

	// -1 means invalid or error, 0 means "up", 1 means "down", 2 means "left", 3 means "right"
};

void setCarrier(){
	//std::cout << carrier->getIsSunk();

	string desPose = "";

	cout << "Enter the desired position of your carrier: ";
	cin >> desPose;

	if(isValidPos(desPose, 2) == 1){
		if(desPos.at(1) == 1 && (int)desPos.at(2) == 0){
			carrier = new Ship(2, "Carrier", false, desPose.at(0), 10);
		}
		else{
			carrier = new Ship(2, "Carrier", false, desPose.at(0), (int)desPose.at(1));
		}
	}
	else if(isValidPos(desPose, 2) == 3){
		if(desPos.at(1) == 1 && (int)desPos.at(2) == 0){
			carrier = new Ship(2, "Carrier", true, desPose.at(0), 10);
		}
		else{
			carrier = new Ship(2, "Carrier", true, desPose.at(0), (int)desPose.at(1));
		}
	}
	else{
		cout << "Invalid position.";
	}
}
void setBattleship(){
	std::cout << battleship->getIsSunk();
}
void setSubmarine(){
	std::cout << submarine->getIsSunk();
}
void setCruiser(){
	std::cout << cruiser->getIsSunk();
}
void setDestroyer(){
	std::cout << destroyer->getIsSunk();
}

