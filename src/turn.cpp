#include "../include/turn.h"

//gameover boolean
bool Turn::gameover(Computer *computer, User *user){
	return (lose(user) || win(computer));
}

//check win scenario
bool Turn::win(Computer *computer){
	int sunkNum = 0;

	if(computer->carrier->getIsSunk(computer->board)){ sunkNum++; }
	if(computer->battleship->getIsSunk(computer->board)){ sunkNum++; }
	if(computer->submarine->getIsSunk(computer->board)){ sunkNum++; }
	if(computer->cruiser->getIsSunk(computer->board)){ sunkNum++; }
	if(computer->destroyer->getIsSunk(computer->board)){ sunkNum++; }

	return (sunkNum == 5);
}

//check lose scenario
bool Turn::lose(User *user){
	int sunkNum = 0;

	if(user->carrier->getIsSunk(user->board)){ sunkNum++; }
	if(user->battleship->getIsSunk(user->board)){ sunkNum++; }
	if(user->submarine->getIsSunk(user->board)){ sunkNum++; }
	if(user->cruiser->getIsSunk(user->board)){ sunkNum++; }
	if(user->destroyer->getIsSunk(user->board)){ sunkNum++; }

	return (sunkNum == 5);
}

//-----------------------Hitting ship--------------------------
void Turn::user_hit_ship(User *user, Computer *computer, Board *board_user, Board *board_computer){
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

	// Need a change status method for board.....
	if(board_computer->getStatus(a) == 1){
		//run change status method
		cout << "Hit!\n";
	}
	else if(board_computer->getStatus(a) == 0){
		//run change status method
		cout << "Miss!\n";		
	}

	/* Checks if it was sunk this turn or not. If it returns false that means it hasn't been sunk left
	   If it returns false, it attempts to sink it */
	if(!computer_carrier && computer->carrier->getIsSunk(computer->board)){
		computer->carrier->sinkShip();
		cout << "You have sunk a ship!\n";
		computer_carrier = true;
	}
	if(!computer_battleship && computer->battleship->getIsSunk(computer->board)){
		computer->battleship->sinkShip();
		cout << "You have sunk a ship!\n";
		computer_battleship = true;
	}
	if(!computer_submarine && computer->submarine->getIsSunk(computer->board)){
		computer->submarine->sinkShip();
		cout << "You have sunk a ship!\n";
		computer_submarine = true;
	}
	if(!computer_cruiser && computer->cruiser->getIsSunk(computer->board)){
		computer->cruiser->sinkShip();
		cout << "You have sunk a ship!\n";
		computer_cruiser = true;
	}
	if(!computer_destroyer && computer->destroyer->getIsSunk(computer->board)){
		computer->destroyer->sinkShip();
		cout << "You have sunk a ship!\n";
		computer_destroyer = true;
	}
}

void Turn::computer_hit_ship(User *user, Computer *computer, Board *board_user, Board *board_computer){
	int b, a = 0;
	do{
		int b = computer->guess();
	}while(b == 2 || b == 3);

	if(board_user->getStatus(a) == 1){
		//need to run change status method
		cout << "One of your ships have been hit!\n";
	}
	else if(board_user->getStatus(a) == 0){
		cout << "The computer missed!\n";		
	}

	/* Checks if it was sunk this turn or not. If it returns false that means it hasn't been sunk left
	   If it returns false, it attempts to sink it */
	if(!user_carrier && user->carrier->getIsSunk(user->board)){
		user->carrier->sinkShip();
		cout << "Computer has sunk a ship!\n";
		user_carrier = true; 
	}
	if(!user_battleship && user->battleship->getIsSunk(user->board)){
		user->battleship->sinkShip();
		cout << "Computer has sunk a ship!\n";
		user_battleship = true; 
	}
	if(!user_submarine && user->submarine->getIsSunk(user->board)){
		user->submarine->sinkShip();
		cout << "Computer has sunk a ship!\n";
		user_submarine = true;
	}
	if(!user_cruiser && user->cruiser->getIsSunk(user->board)){
		user->cruiser->sinkShip();
		cout << "Computer has sunk a ship!\n";
		user_cruiser = true; 
	}
	if(!user_destroyer && user->destroyer->getIsSunk(user->board)){
		user->destroyer->sinkShip();
		cout << "Computer has sunk a ship!\n";
		user_destroyer = true;
	}
}

void Turn::frame(User *user, Computer *computer, Board *board_user, Board *board_computer){

	bool a = false; 
	bool b = false; 
	bool c = false; 

 //Refresh board_computer here
	user_hit_ship(user, computer, board_user, board_computer);
	
	a = win(computer);
	if(a== true){
		cout<<"You win!";
	}
	else{
	computer_hit_ship(user, computer, board_user, board_computer);


//Refresh board_user here
	b = lose(user);
	if(b==true){
		cout<<"You lose.";
	}
	}

	c = gameover(computer, user);

	if(c==true){
		cout<<"Gameover.";
	}

}