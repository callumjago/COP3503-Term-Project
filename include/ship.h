#ifndef SHIP_H
#define SHIP_H
#include "board.h"

class Ship{
	public:
		bool sinkShip();	//attempts sinking the Ship (interp as setter method for state bool isSunk)
		bool getIsSunk(Board board);	//getter method for state bool isSunk
		int getLength();	//getter method for state int length

		int getStart(){ return (((int)getStartX() - 65) * 10) + getStartY(); };

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

			index = 0;

			
			this->isHorizontal = isHorizontal;
			this->startX = (int)startX;
			this->startY = startY;

			this->name = name;	

		}

		void Initialize(Board *&b);
		
		int index;
		
	private:
		int length;
		int startX;
		int startY;
		//int* status;
		int* location;
		bool isSunk;
		bool isHorizontal;
		string name;

		
};
#endif
