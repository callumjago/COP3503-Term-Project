#include "../include/turn.h"


//Check win scenario
bool Turn::win(Computer ****computer, int index){
	int sunkNum = 0;

	if((***computer)->carrier->getIsSunk((***computer)->board, (***computer)->carrier->getStartIndex())){ sunkNum = 5; }
	/*if((***computer)->battleship->getIsSunk((***computer)->board, (***computer)->battleship->getStartIndex())){ sunkNum++; }
	if((***computer)->submarine->getIsSunk((***computer)->board, (***computer)->submarine->getStartIndex())){ sunkNum++; }
	if((***computer)->cruiser->getIsSunk((***computer)->board, (***computer)->cruiser->getStartIndex())){ sunkNum++; }
	if((***computer)->destroyer->getIsSunk((***computer)->board, (***computer)->destroyer->getStartIndex())){ sunkNum++; }*/

	return (sunkNum == 5);
}

//Check lose scenario
bool Turn::lose(User ****user, int index){
	int sunkNum = 0;

	if((***user)->carrier->getIsSunk((***user)->board, (***user)->carrier->getStartIndex())){ sunkNum++; }
	if((***user)->battleship->getIsSunk((***user)->board, (***user)->battleship->getStartIndex())){ sunkNum++; }
	if((***user)->submarine->getIsSunk((***user)->board, (***user)->submarine->getStartIndex())){ sunkNum++; }
	if((***user)->cruiser->getIsSunk((***user)->board, (***user)->cruiser->getStartIndex())){ sunkNum++; }
	if((***user)->destroyer->getIsSunk((***user)->board, (***user)->destroyer->getStartIndex())){ sunkNum++; }

	return (sunkNum == 5);
}

//-----------------------Hitting ship--------------------------
void Turn::user_hit_ship(User ***user, Computer ***computer, Board ***board_user, Board ***board_computer, bool * a_return){
	int a = 0, b = 0;
	do{
		a = (**user)->guess();

		if(a == -1){
			cout << "Invalid location, please guess again.\n"; continue;
		}

		b = (**board_computer)->getStatus(a);

		if(b == 2 || b == 3){
			cout << "Location already guessed, please guess again.\n";
		}
	}while(b == 2 || b == 3);

	//Need a change status method for board.....
	if((**board_computer)->getStatus(a) == 1){

		(**board_computer)->setStatus(a, 2);
		cout << "Hit!\n";
	}
	else if((**board_computer)->getStatus(a) == 0){

		(**board_computer)->setStatus(a, 3);
		cout << "Miss!\n";		
	}

	/*Checks if it was sunk this turn or not. If it returns false that means it hasn't been sunk left
	If it returns false, it attempts to sink it */
	if(!computer_carrier && (**computer)->carrier->getIsSunk((**computer)->board, (**computer)->carrier->getStartIndex())){
		(**computer)->carrier->sinkShip();
		cout << "You have sunk a ship!\n";
		computer_carrier = true;
	}
	
	if(!computer_battleship && (**computer)->battleship->getIsSunk((**computer)->board, (**computer)->battleship->getStartIndex())){
		(**computer)->battleship->sinkShip();
		cout << "You have sunk a ship!\n";
		computer_battleship = true;
	}
	if(!computer_submarine && (**computer)->submarine->getIsSunk((**computer)->board, (**computer)->submarine->getStartIndex())){
		(**computer)->submarine->sinkShip();
		cout << "You have sunk a ship!\n";
		computer_submarine = true;
	}
	if(!computer_cruiser && (**computer)->cruiser->getIsSunk((**computer)->board, (**computer)->cruiser->getStartIndex())){
		(**computer)->cruiser->sinkShip();
		cout << "You have sunk a ship!\n";
		computer_cruiser = true;
	}
	if(!computer_destroyer && (**computer)->destroyer->getIsSunk((**computer)->board, (**computer)->destroyer->getStartIndex())){
		(**computer)->destroyer->sinkShip();
		cout << "You have sunk a ship!\n";
		computer_destroyer = true;
	}
	*a_return = win(&computer, a);
}

//Represents a computer hitting a ship
void Turn::computer_hit_ship(User ***user, Computer ***computer, Board ***board_user, Board ***board_computer, bool * b_return){
	int b, a = 0;
/*
	do{
		int a = (**computer)->guess();

		cout << "Computer Guess: " << (**board_user)->getId(a) << endl;
	}while(b == 2 || b == 3);

	if((**board_user)->getStatus(a) == 1){

		(**board_user)->setStatus(a, 2);
		cout << "One of your ships have been hit!\n";
	}
	else if((**board_user)->getStatus(a) == 0){

		(**board_user)->setStatus(a, 3);
		cout << "The computer missed!\n";		
	}

*/
	do{
		a = (**computer)->guess();

		if(a == -1){
			cout << "Invalid location, please guess again.\n"; continue;
		}

		b = (**board_user)->getStatus(a);

		if(b == 2 || b == 3){
			cout << "Location already guessed, please guess again.\n";
		}
	}while(b == 2 || b == 3);

	cout << "Computer Guess: " << (**board_user)->getId(a) << endl;

	//Need a change status method for board.....
	if((**board_user)->getStatus(a) == 1){

		(**board_user)->setStatus(a, 2);
		cout << "Hit!\n";
	}
	else if((**board_user)->getStatus(a) == 0){

		(**board_user)->setStatus(a, 3);
		cout << "Miss!\n";		
	}



	/*Checks if it was sunk this turn or not. If it returns false that means it hasn't been sunk left
	If it returns false, it attempts to sink it */
	if(!user_carrier && (**user)->carrier->getIsSunk((**user)->board, (**user)->carrier->getStartIndex())){
		(**user)->carrier->sinkShip();
		cout << "Computer has sunk a ship!\n";
		user_carrier = true; 
	}
	if(!user_battleship && (**user)->battleship->getIsSunk((**user)->board, (**user)->battleship->getStartIndex())){
		(**user)->battleship->sinkShip();
		cout << "Computer has sunk a ship!\n";
		user_battleship = true; 
	}
	if(!user_submarine && (**user)->submarine->getIsSunk((**user)->board, (**user)->submarine->getStartIndex())){
		(**user)->submarine->sinkShip();
		cout << "Computer has sunk a ship!\n";
		user_submarine = true;
	}
	if(!user_cruiser && (**user)->cruiser->getIsSunk((**user)->board, (**user)->cruiser->getStartIndex())){
		(**user)->cruiser->sinkShip();
		cout << "Computer has sunk a ship!\n";
		user_cruiser = true; 
	}
	if(!user_destroyer && (**user)->destroyer->getIsSunk((**user)->board, (**user)->destroyer->getStartIndex())){
		(**user)->destroyer->sinkShip();
		cout << "Computer has sunk a ship!\n";
		user_destroyer = true;
	}
	*b_return = lose(&user, a);

}

//Represents a frame where gameover is checked
void Turn::frame(User **user, Computer **computer, Board **board_user, Board **board_computer){
	bool a = false; 
	bool b = false; 
	bool c = false; 

	do{
		//Refresh board_computer here
		user_hit_ship(&user, &computer, &board_user, &board_computer, &a);
		(*board_computer)->print_computer_board();
		computer_hit_ship(&user, &computer, &board_user, &board_computer, &b);
		(*board_user)->print_user_board();
		c = a || b;

	} while (c == false);

	if(b == true){
				cout << "You lose.";
			}

	if(a == true){
			cout<<"You win!";
		}

	if(c == true){
		cout << "Gameover.";
	}

}