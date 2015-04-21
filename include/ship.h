#ifndef SHIP_H
#define SHIP_H
#include "board.h"

class Ship{
	private:
		int length;			//Represents the length of the ship
		int startX;			//Represents the integer value of the row
		int startY;			//Represents the integer value of the column 
		bool isSunk;		//True if the ship is sunk, false otherwise
		bool isHorizontal;	//True if the ship is horizontal, false otherwise
		string name;		//Represents the name of the ship

	public:
		bool sinkShip();				//Attempts sinking the Ship (interpret as setter method for state bool isSunk)
		bool getIsSunk(Board *board, int startIndex);	//Getter method for state bool isSunk
		int getLength();				//Getter method for state int length
		int startIndex;

		void Initialize(Board **b, int index);
		int getStartIndex(){ return startIndex; };

		int getStart(){ return (length); };

		char getStartX(){ return startX; };
		int getStartY() { return startY; };
		bool getIsHorizontal(){ return isHorizontal; };
		
		Ship(int length, string name, bool isHorizontal, char startX, int startY):length(length), /*status(NULL)*/ isSunk(false){
			//Initializes status array

			//Converts char to int value
			/*if((int)startX <= 64 || (int)startX >= 75) {
				startX = 'A';
			}
			
			if(startY <= 0 || startY >= 11) {
				startY = 1;
			}
			this->startY = startY;
			this->name = name;	
			this->isHorizontal = isHorizontal;
			/*for(int i = 0; i < length; i++){	//Initializes status array to all 1s
				status[i] = 1;
			}*/
			//perhaps do something for state int* status
			if(length < 0){ this->length = 0; }
			else { this->length = length;}


			this->isHorizontal = isHorizontal;

			if(startX < 'A' || startX > 'J'){
				this->startX = (int)('A') - 65;
			}
			else{
				this->startX = (int)startX - 65;
			}
			
			if(startY < 1 || startY > 10){
				this->startY = 1;
			}
			else{
				this->startY = startY;
			}

			this->name = name;

			this->startIndex = ((startX - 'A') * 10) + startY;
		}
		
		
};
#endif
