#include "ship.h"

class Player{
	private:

	public:
		Board *board;	//Represents the board which will be implemented by User and Computer

		Ship *carrier;
		Ship *battleship;
		Ship *submarine;
		Ship *cruiser;
		Ship *destroyer;

		/*Represents an abstract method which needs to be implemented by 
		both User and Computer to determine if a desired position is a valid one*/
		virtual int isValidPos(string desPos, int length) = 0;

		void setCarrier(bool *addSuccess); 		//Sets the Carrier ship and changes addSuccess to true if the addition was a success, false otherwise
		void setBattleship(bool *addSuccess); 	//Sets the Battleship ship and changes addSuccess to true if the addition was a success, false otherwise
		void setSubmarine(bool *addSuccess); 	//Sets the Submarine ship and changes addSuccess to true if the addition was a success, false otherwise
		void setCruiser(bool *addSuccess); 		//Sets the Cruiser ship and changes addSuccess to true if the addition was a success, false otherwise
		void setDestroyer(bool *addSuccess); 	//Sets the Destroyer ship and changes addSuccess to true if the addition was a success, false otherwise

		
	protected:
		string desPos; 		//Represents a desired position to place ships
		int choice; 		//Represents the choice of orientation of the ship during placement
};