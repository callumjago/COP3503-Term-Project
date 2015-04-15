//Need to pass Computer into Lose to check ship contained by Computer 
//***not sure how to do that

//USING GETISSUNK vs ISSUNK???

#include "../include/turn.h"

//gameover boolean
bool Turn::gameover(Computer *computer, User *user){
	return (lose(computer) || win(user));
}

//check lose
bool Turn::lose(Computer *computer){
	int sunkNum = 0;

	if(computer->carrier->getIsSunk()){ sunkNum++; }
	if(computer->battleship->getIsSunk()){ sunkNum++; }
	if(computer->submarine->getIsSunk()){ sunkNum++; }
	if(computer->cruiser->getIsSunk()){ sunkNum++; }
	if(computer->destroyer->getIsSunk()){ sunkNum++; }

	return (sunkNum == 5);
}

//check win
bool Turn::win(User *user){
	int sunkNum = 0;

	if(user->carrier->getIsSunk()){ sunkNum++; }
	if(user->battleship->getIsSunk()){ sunkNum++; }
	if(user->submarine->getIsSunk()){ sunkNum++; }
	if(user->cruiser->getIsSunk()){ sunkNum++; }
	if(user->destroyer->getIsSunk()){ sunkNum++; }

	return (sunkNum == 5);
}

//-----------------------Hitting ship--------------------------
void Turn::user_hit_ship(User *user, Computer *computer, Board *board_user, Board *computer_user){
	int a = 0, b = 0;
	do{
		a = user->guess();
		if(a == -1){
			cout << "Invalid location, please guess again.\n"; continue;
		}

		b = board_computer->getStatus(a);
		if(b == 2 || b == 3){
			cout << "Location already guessed, please guess again.\n";
		}
	}while(b == 2 || b == 3);

	// Need a check status and change status method for board.....
	if(board_computer->getStatus(a) == 1){
		//run change status method
		cout << "Hit!\n";
	}
	else if(board_computer->getStatus(a) == 0){
		cout << "Miss!\n";		//possible need another value in case it was guessed so it can say that the location was already guessed
	}

	/* Checks if it was sunk this turn or not. If it returns false that means it hasn't been sunk left
	   If it returns false, it attempts to sink it */
	if(!computer_carrier && computer->carrier->getIsSunk()){
		computer->carrier->sinkShip();
		cout << "You have sunk a ship!\n";
		computer_carrier = true;
	}
	if(!computer_battleship && computer->battleship->getIsSunk()){
		computer->battleship->sinkShip();
		cout << "You have sunk a ship!\n";
		computer_battleship = true;
	}
	if(!computer_submarine && computer->submarine->getIsSunk()){
		computer->submarine->sinkShip();
		cout << "You have sunk a ship!\n";
		computer_submarine = true;
	}
	if(!computer_cruiser && computer->cruiser->getIsSunk()){
		computer->cruiser->sinkShip();
		cout << "You have sunk a ship!\n";
		computer_cruiser = true;
	}
	if(!computer_destroyer && computer->destroyer->getIsSunk()){
		computer->destroyer->sinkShip();
		cout << "You have sunk a ship!\n";
		computer_destroyer = true;
	}
}

void Turn::computer_hit_ship(User *user, Computer *computer, Board *board_user, Board *computer_user){
	do{
		int b = computer->guess();
	}while(b == 2 || b == 3);

	if(board_user->getStatus(a) == 1){
		//need to run change status method
		cout << "Hit!\n";
	}
	else if(board_user->getStatus(a) == 0){
		cout << "Miss!\n";		//possible need another value in case it was guessed so it can say that the location was already guessed
	}

	/* Checks if it was sunk this turn or not. If it returns false that means it hasn't been sunk left
	   If it returns false, it attempts to sink it */
	if(!user_carrier && user->carrier->getIsSunk()){
		user->carrier->sinkShip();
		cout << "Computer has sunk a ship!\n";
		user_carrier = true; 
	}
	if(!user_battleship && user->battleship->getIsSunk()){
		user->battleship->sinkShip();
		cout << "Computer has sunk a ship!\n";
		user_battleship = true; 
	}
	if(!user_submarine && user->submarine->getIsSunk()){
		user->submarine->sinkShip();
		cout << "Computer has sunk a ship!\n";
		user_submarine = true;
	}
	if(!user_cruiser && user->cruiser->getIsSunk()){
		user->cruiser->sinkShip();
		cout << "Computer has sunk a ship!\n";
		user_cruiser = true; 
	}
	if(!user_destroyer && user->destroyer->getIsSunk()){
		user->destroyer->sinkShip();
		cout << "Computer has sunk a ship!\n";
		user_destroyer = true;
	}
}

void Turn::turn(User *user, Computer *computer, Board *board_user, Board *computer_user){
}