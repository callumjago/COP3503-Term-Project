#include "../include/user.h"


bool User :: guess(){

	string guess = "";
	cout << "Enter your guess: ";
	cin >> guess;

	return false;
};

bool User :: setShip(){

	string desPose = "";

	cout << "Enter the desired position of your carrier: ";
	cin >> desPose;

	isValidPos(desPose, 2);

	return false;
	//Create instances for all 5 ships, until isValidPosition is a success for all 5 ships.
}

//Cancel the up position.
int User :: isValidPos(string desPos, int length){
	string direction = ""; //Can be either up, down, or right.
	
	bool right = true;
	bool up = true;
	bool down = true;


	char letter = desPos.at(0);
	int digit = desPos.at(1); //Need to make a special case for the digit 10.

	char tempLetter = 'A';
	int tempDigit = 1;

	int index = ((letter - 'A') * 10) + digit; //Determines the index of the position in the board.
	int tempIndex = 0;


	if(letter >= 'A' && letter <= 'J' && digit >= 1 && digit <= 9){
	}
	else{
		cout << "Invalid position choice.";
	}

	
	if(board->getStatus(index) == 0){
		//Checks to see if up is possible.
		if(letter - length >= 'A'){
			for(int i = 1; i <= length; i++){
				tempLetter = letter - i;
				tempDigit = digit;

				tempIndex = ((tempLetter - 'A') * 10) + tempDigit;

				if(board->getStatus(index) == 0){
				}
				else{
					up = false;
				}
			}

		}

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
		if(!right && !up && !down){
			cout << "Unable to place a ship of this length there.";
		}
		else if(right && up && down){
			cout << "Choose to orientate the ship right, up, or down: ";
			cin >> direction;
			//Set the ship coordinates based on choice.
		}
		else if(right && up){
			cout << "Choose to orientate the ship right or up: ";
			cin >> direction;
			//Set the ship coordinates based on choice.
		}
		else if(right && down){
			cout << "Choose to orientate the ship right or down: ";
			cin >> direction;
			//Set the ship coordinates based on choice.
		}
		else if(down && up){
			cout << "Choose to orientate the ship up or down: ";
			cin >> direction;
			//Set the ship coordinates based on choice.
		}
		else if(up){
			//Set the ship coordinates.
		}
		else if(down){
			//Set the ship coordinates.
		}
		else if(right){
			//Set the ship coordinates.
		}





	}
	else{
		cout << "Ship already placed there.";
	}
	

		//Returns an array of directions that the user can oriente the ship, based on location availabilities.
		//Eion: I changed this to return an int corresponding to the chosen orientation rather than an array of options (choose within this method)
	return 0;	
};



int main(){

	
	return 0;
}