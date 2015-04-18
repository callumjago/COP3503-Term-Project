#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>

using namespace std;

class Board{

	private:
		/*The thought here is that we have one board struct to hold all the tiles and all the ships
		So we can access the  board, the tiles, or the ships all through one struct eventually
		TODO: Assign ships to the board */


		//Defines the structure that represents a tile on the board of Battleship (A1, D4, etc.)
		typedef struct tile {
			//Potential to put total number of ships currently on the board
			string str;		//Title of the tile (A1, D3, etc)
			int id_num; 	//Number that represents its position index in the board
			int status; 	//Status values: 0 - empty; 1 - ship present; 2 - hit; 3 - miss
		} tile_t;

		
		//Defines the structure that represents the 100 positions on the Battleship board
		typedef struct full_board {
			tile * tiles; 	//Represents all the tiles on the Battleship board
		} full_board_t;
		

		//Represents the board that will be used when initializing a Board object
		struct full_board board; 

		//Represents all of the possible statuses that a tile can have on the board
		int possibleStatus[];

	public:
		void populate(); 				//Sets all of the statuses of the board to 0 - empty
		void print_user_board(); 		//Prints the board
		void print_computer_board();	//Prints the board of the computer	
		void add_tiles_to_board(); 		//Adds tiles to the board
		
		string getId(int index){ return values[index].str; }; 		//Returns the name of the position at the specific index (A1, D3, etc.)
		int getStatus(int index){ return values[index].status; }; 	//Returns the status of the position at the specfic index
		void setStatus(int index, int status); 						//Sets the status of the position at the index specified to the status specified

		// Populate the board upon initialization
		Board(){
			populate(); 
			for(int i = 0; i < 101; i++){
				values[i].status = 0;
			}
			
		}
		
		//Represents all 100 values of the board (1 - 100 will be printed)
		struct tile values[101];
};

#endif