#include "../include/board.h"
#include "../include/ship.h"
#include "../include/user.h"
#include "../include/display.h"
#include "../include/turn.h"
#include <unistd.h>

int main(int argc, char *argv[1]){

	//Creates a user_one to play the game
	User user_one = User();
	User user_two = User();

	bool addSuccess = false;			//Represents the success of the ship placement
	//Creates a computer to play the game against the user
	
	Computer computer = Computer();
	/*
	computer.setCarrier(&addSuccess);
	addSuccess = false;
	computer.setBattleship(&addSuccess);
	addSuccess = false;
	computer.setSubmarine(&addSuccess);
	addSuccess = false;
	computer.setCruiser(&addSuccess);
	addSuccess = false;
	computer.setDestroyer(&addSuccess);
	addSuccess = false;
	*/

	

	//Creates a Turn object in order to play the game after the ships are placed.
	Turn turn = Turn();


	//Creates a Display object in order to display to the terminal
	Display out = Display();
	Display out_two = Display();
	out.push_to_first_display("Player 1 Game Board\n");
	out.push_to_first_display("---------------\n"); //Creates a buffer between the output
	out_two.push_to_second_display("Player 2/Computer Game Board\n");
	out_two.push_to_second_display("---------------\n"); //Creates a buffer between the output

	//Prints the board on another screen
	user_one.getBoard().print_user_board();
	//computer.getBoard().print_computer_board();


	//Prompts the user_one to enter the ships based on length
	cout << "\nThere are 5 ships for you to place\n";
	cout << "We will now guide you through the placement procedure.\n";

	int length;
	bool allowed_ship = false;			//Represents if the ship was allowed to be placed
	bool second_third = false;			//Represents the possibility of having two length 3 ships
	int allowed_lengths[] = {2,3,3,4,5};
	

	//While there are still ships to create
	while ((allowed_lengths[0] != 0) | (allowed_lengths[1] != 0) | (allowed_lengths[2] != 0) | (allowed_lengths[3] != 0) | (allowed_lengths[4] != 0))
	{
		cout << "\nEnter the ship that you want to place using the numbers provided \n"; 
		cout << "Carrier:     5 \n";
		cout << "Battleship:  4 \n"; 
		cout << "Submarine:   3 \n"; 
		cout << "Cruiser:     3 \n"; 
		cout << "Destroyer:   2 \n\n";
		cout << "Ship Number: "; 
		cin >> length;

		//If the input in not an integer, it will trigger an invalid length
		if(cin.fail()){
			cin.clear(); // LINE 9
			cout << "Invalid length.\n";
		}
		

		else{
			//Loop through allowed length array and see if requested length is allowed and unused
			for (int i = 0; i < 5; i++){

				if (length == allowed_lengths[i]) //Length is allowed and available
				{
				 	//Remove from array
					allowed_ship = true;		  //Untriggers if statment below
					switch(length){
						case 2: user_one.setDestroyer(&addSuccess);
							break;
						case 3: 
							if (second_third == false)
							{
								user_one.setSubmarine(&addSuccess);
								second_third = true;
							}else{
								user_one.setCruiser(&addSuccess);
							}
							break;
						case 4: user_one.setBattleship(&addSuccess);
							break;
						case 5: user_one.setCarrier(&addSuccess);
							break;
					}

					if(addSuccess == false){
						cout << "\nUnable to set ship.\n\n";
					}
					else{
						cout << "\nShip added - success!\n\n";
						allowed_lengths[i] = 0;
					}
					break;
				}
			}
			if (allowed_ship == false)			//If length is not allowed or is unavailable
			{
				cout << "\nUnavailable ship length. Here are the possible ship lengths to choose from:\n";

				for (int i = 0; i < 5; i++)   	//Print available lengths
				{
					if (allowed_lengths[i] != 0)
					{
						cout << allowed_lengths[i] << " ";
					}
				}
				cout << endl;
			}
			allowed_ship = false; //Reset
			addSuccess = false;
		}
		user_one.getBoard().print_user_board();
		
	}

	
/*
	User *pointUser = &user_one;
	Computer *pointComputer = &computer;
	Board *pointUserBoard = user_one.board;
	Board *pointComputerBoard = computer.board;


	turn.frame(pointUser, pointComputer, pointUserBoard, pointComputerBoard);
		*/
	//Main loop for runnning program
		//while(1);
	/*
	cout << "How long is this ship? " << test.getLength() << endl;
	cout << "Is this ship sunk? " << test.getIsSunk() << endl;
	cout << "Sink this ship! " << test.sinkShip() << endl;
	cout << "Is this ship sunk? " << test.getIsSunk() << endl << endl;
	*/
	
	return 0;
}