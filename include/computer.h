#ifndef COMPUTER_H
#define COMPUTER_H

#include "user.h"


class Computer : public Player{
	public:
		Computer(){
			board = new Board(); 	//Defines the Board object
			choice = -1; 			//Sets the choice of direction of orientation to be -1
		}
		void printShips();

		void setCarrier(bool *addSuccess); 		//Sets the Carrier ship and changes addSuccess to true if the addition was a success, false otherwise
		void setBattleship(bool *addSuccess); 	//Sets the Battleship ship and changes addSuccess to true if the addition was a success, false otherwise
		void setSubmarine(bool *addSuccess); 	//Sets the Submarine ship and changes addSuccess to true if the addition was a success, false otherwise
		void setCruiser(bool *addSuccess); 		//Sets the Cruiser ship and changes addSuccess to true if the addition was a success, false otherwise
		void setDestroyer(bool *addSuccess); 	//Sets the Destroyer ship and changes addSuccess to true if the addition was a success, false otherwise

		int guess(); 									//Generates a guess position to try to sink the user's ships
		int formulate(int length, int *index_return); 						//Formulates and returns an integer value representing where the computer ships will be oriented
		int isValidPos(string desPos, int length, int *index_return){return 0;}; 		//Checks if the desired position to place a ship is a valid position
		int isValidCompPos(string desPos, int length, int **index_return);
		Board getBoard(){ return *this->board; }; 	//Returns the board

	private:
};

#endif