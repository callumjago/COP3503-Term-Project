#include "../include/user.h"
#include <iostream>



bool User::guess(int* index){

	string guess = "";
	cout << "Enter your guess: ";
	cin >> guess;

	char letter = guess.at(0);
	int digit = guess.at(1);
	if(digit == 1 && (int)guess.at(2) == 0){
		digit = 10;
	}

	*index = ((letter - 'A') * 10) + digit; //Determines the index of the position in the board.
	

	return false;
};


// -1 means invalid or error, 0 means "up", 1 means "down", 2 means "left", 3 means "right"
int User::isValidPos(string desPos, int length, int* index){
	string direction = ""; //Can be either up, down, or right.
	
	bool right = true;
	bool down = true;


	char letter = desPos.at(0);
	int digit = (int)desPos.at(1) - 48;
	if(desPos.length() == 3 && digit == 1 && desPos.at(2) == '0'){
		digit = 10;
	}


	char tempLetter = 'A';
	int tempDigit = 1;

<<<<<<< HEAD
	*index = ((int)(letter - 'A') * 10) + digit; //Determines the index of the position in the board.
=======
	int index = ((int)(letter - 'A') * 10) + digit; //Determines the index of the position in the board.
>>>>>>> Fleshed out user.cpp to set all ships.
	int tempIndex = 0;


	if(letter >= 'A' && letter <= 'J' && digit >= 1 && digit <= 10){
		if(board->getStatus(*index) == 0){

			//Checks to see if down is possible.
			if(letter + length >= 'J'){
				for(int i = 1; i <= length; i++){
					tempLetter = letter + i;
					tempDigit = digit;

					tempIndex = ((tempLetter - 'A') * 10) + tempDigit;

					if(board->getStatus(*index) == 0){
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

					if(board->getStatus(*index) == 0){
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
				cout << "\nChoose to orientate the ship right or down: ";
				cin >> direction;
				if(direction.compare("right") == 0){
					choice = 3;
				}
				else if(direction.compare("down") == 0){
					choice = 1;
				}
				else{
					// Represents that the choice of right/down is invalid.
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

void User::setCarrier(bool &addSuccess){
	//std::cout << carrier->getIsSunk();

	string desPos = "";

	cout << "\nEnter the desired position of your carrier: ";
	cin >> desPos;

<<<<<<< HEAD
	int index;
	int choice = isValidPos(desPose, 5, &index);
=======
	choice = isValidPos(desPos, 5);
>>>>>>> Fleshed out user.cpp to set all ships.

	if(choice == 1){
		if((signed)desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(5, "Carrier", false, desPos.at(0), 10);
			addSuccess = true;
		}
		else{
<<<<<<< HEAD
			carrier = new Ship(5, "Carrier", false, desPose.at(0), (int)(desPose.at(1) - 48));
=======
			carrier = new Ship(5, "Carrier", false, desPos.at(0), (int)(desPos.at(1) - 48));
			addSuccess = true;
>>>>>>> Fleshed out user.cpp to set all ships.
		}
	}
	
	else if(choice == 3){
		if(desPos.at(1) == 1 && (int)desPos.at(2) == 0){
			carrier = new Ship(5, "Carrier", true, desPos.at(0), 10);
			addSuccess = true;
		}
		else{
			carrier = new Ship(5, "Carrier", true, desPos.at(0), (int)(desPos.at(1) - 48));
			addSuccess = true;
		}
	}
	else{
		
	}
}
void User::setBattleship(bool &addSuccess){
	//std::cout << battleship->getIsSunk();

	string desPos = "";

	cout << "\nEnter the desired position of your battleship: ";
	cin >> desPos;

	choice = isValidPos(desPos, 4);

	if(choice == 1){
		if((signed)desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(4, "Battleship", false, desPos.at(0), 10);
			addSuccess = true;
		}
		else{
			carrier = new Ship(4, "Battleship", false, desPos.at(0), (int)(desPos.at(1) - 48));
			addSuccess = true;
		}
	}
	
	else if(choice == 3){
		if(desPos.at(1) == 1 && (int)desPos.at(2) == 0){
			carrier = new Ship(4, "Battleship", true, desPos.at(0), 10);
			addSuccess = true;
		}
		else{
			carrier = new Ship(4, "Battleship", true, desPos.at(0), (int)(desPos.at(1) - 48));
			addSuccess = true;
		}
	}
	else{
		
	}
}
void User::setSubmarine(bool &addSuccess){
	//std::cout << submarine->getIsSunk();

	string desPos = "";

	cout << "\nEnter the desired position of your submarine: ";
	cin >> desPos;

	choice = isValidPos(desPos, 3);

	if(choice == 1){
		if((signed)desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(3, "Submarine", false, desPos.at(0), 10);
			addSuccess = true;
		}
		else{
			carrier = new Ship(3, "Submarine", false, desPos.at(0), (int)(desPos.at(1) - 48));
			addSuccess = true;
		}
	}
	
	else if(choice == 3){
		if(desPos.at(1) == 1 && (int)desPos.at(2) == 0){
			carrier = new Ship(3, "Submarine", true, desPos.at(0), 10);
			addSuccess = true;
		}
		else{
			carrier = new Ship(3, "Submarine", true, desPos.at(0), (int)(desPos.at(1) - 48));
			addSuccess = true;
		}
	}
	else{
		
	}
}
void User::setCruiser(bool &addSuccess){
	//std::cout << cruiser->getIsSunk();

	string desPos = "";

	cout << "\nEnter the desired position of your cruiser: ";
	cin >> desPos;

	choice = isValidPos(desPos, 3);

	if(choice == 1){
		if((signed)desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(3, "Cruiser", false, desPos.at(0), 10);
			addSuccess = true;
		}
		else{
			carrier = new Ship(3, "Cruiser", false, desPos.at(0), (int)(desPos.at(1) - 48));
			addSuccess = true;
		}
	}
	
	else if(choice == 3){
		if(desPos.at(1) == 1 && (int)desPos.at(2) == 0){
			carrier = new Ship(3, "Cruiser", true, desPos.at(0), 10);
			addSuccess = true;
		}
		else{
			carrier = new Ship(3, "Cruiser", true, desPos.at(0), (int)(desPos.at(1) - 48));
			addSuccess = true;
		}
	}
	else{
		
	}
}
void User::setDestroyer(bool &addSuccess){
	//std::cout << destroyer->getIsSunk();

	string desPos = "";

	cout << "\nEnter the desired position of your destroyer: ";
	cin >> desPos;

	choice = isValidPos(desPos, 2);

	if(choice == 1){
		if((signed)desPos.length() > 2 && desPos.at(1) == '1' && desPos.at(2) == '0'){
			carrier = new Ship(2, "Destroyer", false, desPos.at(0), 10);
			addSuccess = true;
		}
		else{
			carrier = new Ship(2, "Destroyer", false, desPos.at(0), (int)(desPos.at(1) - 48));
			addSuccess = true;
		}
	}
	
	else if(choice == 3){
		if(desPos.at(1) == 1 && (int)desPos.at(2) == 0){
			carrier = new Ship(2, "Destroyer", true, desPos.at(0), 10);
			addSuccess = true;
		}
		else{
			carrier = new Ship(2, "Destroyer", true, desPos.at(0), (int)(desPos.at(1) - 48));
			addSuccess = true;
		}
	}
	else{
		
	}
}

