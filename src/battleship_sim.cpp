#include "../include/board.h"
#include "../include/ship.h"
#include "../include/user.h"
#include "../include/display.h"
#include <unistd.h>




int main(int argc, char *argv[1]){

	//Board temp;
	//temp.print_board();
	//temp.add_tiles_to_board();

	User user = User();
	Display out = Display();

	out.push_to_display("");
	usleep(5000);
	user.getBoard().print_board();

	cout << "\nThere are 5 ships in total of length 5,4,3,3,2.\n";
	cout << "We will now guide you through the placement procedure.\n\n";
	cout << "Please choose your first ship.\n";

	int length;
	bool allowed_ship = false;
	bool second_third = false;
	int allowed_lengths[] = {2,3,3,4,5};
	bool addSuccess = false;

	// While there are still ships to create
	while ((allowed_lengths[0] != 0) | (allowed_lengths[1] != 0) | (allowed_lengths[2] != 0) | (allowed_lengths[3] != 0) | (allowed_lengths[4] != 0))
	{
		cout << "\nEnter the ship length that you want to place: "; 
		cin >> length;

		if(cin.fail()){
			cin.clear(); // LINE 9
			cout << "\nInvalid length.\n";
		}
		

		else{
			// Loop through allowed length array and see if requested length is allowed and unused
			for (int i = 0; i < 5; i++){

				if (length == allowed_lengths[i]) // length is allowed and available
				{
				 	  // Remove from array
					allowed_ship = true;		  // Untriggers if statment below
					switch(length){
						case 2: user.setDestroyer(&addSuccess);
							break;
						case 3: 
							if (second_third == false)
							{
								user.setSubmarine(&addSuccess);
								second_third = true;
							}else{
								user.setCruiser(&addSuccess);
							}
							break;
						case 4: user.setBattleship(&addSuccess);
							break;
						case 5: user.setCarrier(&addSuccess);
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
			if (allowed_ship == false)			  // If length is not allowed or is unavailable
			{
				cout << "\nUnavailable ship length.\n";

				for (int i = 0; i < 5; i++)   // Print available lengths
				{
					if (allowed_lengths[i] != 0)
					{
						cout << allowed_lengths[i] << " ";
					}
				}
				cout << endl;
			}
		
			allowed_ship = false; // reset

		
		}


		//user.getBoard().print_board();
	}
		

	// main loop for runnning program
		while(1);
	/*
	cout << "How long is this ship? " << test.getLength() << endl;
	cout << "Is this ship sunk? " << test.getIsSunk() << endl;
	cout << "Sink this ship! " << test.sinkShip() << endl;
	cout << "Is this ship sunk? " << test.getIsSunk() << endl << endl;
	*/
	

	return 0;
}