#include "../include/board.h"
#include "../include/ship.h"
#include "../include/user.h"
#include "../include/display.h"
#include <unistd.h>

int main(int argc, char *argv[1]){

	//Creates a user_one to play the game
	User user_one = User();
	User user_two = User();

	//Creates a Display object in order to display to the terminal
	Display out = Display();
	Display out_two = Display();
	out.push_to_first_display("Player 1 Game Board\n");
	out.push_to_first_display("---------------\n"); //Creates a buffer between the output
	out_two.push_to_second_display("Player 2/Computer Game Board\n");
	out_two.push_to_second_display("---------------\n"); //Creates a buffer between the output

	//Prints the board on another screen
	user_one.getBoard().print_board();
	//user_two.getBoard().print_board();
	//user_two.getBoard().print_board();

	
	

	//Prompts the user_one to enter the ships based on length
	cout << "\nThere are 5 ships for you to place\n";
	cout << "We will now guide you through the placement procedure.\n";

	int length;
	bool allowed_ship = false;			//Represents if the ship was allowed to be placed
	bool second_third = false;			//Represents the possibility of having two length 3 ships
	int allowed_lengths[] = {2,3,3,4,5};
	bool addSuccess = false;			//Represents the success of the ship placement

	//While there are still ships to create
	while ((allowed_lengths[0] != 0) | (allowed_lengths[1] != 0) | (allowed_lengths[2] != 0) | (allowed_lengths[3] != 0) | (allowed_lengths[4] != 0))
	{
		cout << "\nEnter the ship that you want to place using the numbers provided \n"; 
		cout << "Carrier:     5 \n";
		cout << "Battleship:  4 \n"; 
		cout << "Submarine:   3 \n"; 
		cout << "Cruiser:     3 \n"; 
		cout << "Destroyer:   2 \n";
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
						cout << "\nUnable to set ship.";
					}
					else{
						cout << "\nShip added - success!";
						//allowed_lengths[i] = 0;
					}
					break;
				}
			}
			if (allowed_ship == false)			//If length is not allowed or is unavailable
			{
				cout << "\nUnavailable ship length.\n";

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
		}
		//user_one.getBoard().print_board();
	}
		
	//Main loop for runnning program
		while(1);
	/*
	cout << "How long is this ship? " << test.getLength() << endl;
	cout << "Is this ship sunk? " << test.getIsSunk() << endl;
	cout << "Sink this ship! " << test.sinkShip() << endl;
	cout << "Is this ship sunk? " << test.getIsSunk() << endl << endl;
	*/
	
	return 0;
}