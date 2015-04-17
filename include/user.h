#ifndef USER_H
#define USER_H

#include "player.h"

class User: public Player{
	public:
		//Initializes a new User object
		User(){
			board = new Board(); 	//Defines the Board object
			choice = -1; 			//Sets the choice of direction of orientation to be -1
		}
		
		void setCarrier(bool *addSuccess); 		//Sets the Carrier ship and changes addSuccess to true if the addition was a success, false otherwise
		void setBattleship(bool *addSuccess); 	//Sets the Battleship ship and changes addSuccess to true if the addition was a success, false otherwise
		void setSubmarine(bool *addSuccess); 	//Sets the Submarine ship and changes addSuccess to true if the addition was a success, false otherwise
		void setCruiser(bool *addSuccess); 		//Sets the Cruiser ship and changes addSuccess to true if the addition was a success, false otherwise
		void setDestroyer(bool *addSuccess); 	//Sets the Destroyer ship and changes addSuccess to true if the addition was a success, false otherwise

		void printShips(); 							//Prints a matrix of statuses to represent all the position in the board
		int guess();								//Guesses a position to hit based on user's input
		int isValidPos(string desPos, int length);	//Checks to see if the user input is a valid position

	private:			
};

#endif