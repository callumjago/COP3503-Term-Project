#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class Board{

	private:
		typedef struct tile {
			//Potential to put total number of ships currently on the board.
			string str;
			int id_num;
			int status; //Status values: 0 - empty; 1 - ship present; 2 - hit; 3 - miss
		} tile_t;

		// The thought here is that we have one board struct to hold all the tiles and all the ships
		// So we can access the  board, the tiles, or the ships all through one struct eventually
		// TODO: Assign ships to the board 
		typedef struct full_board {
			tile * tiles;
		} full_board_t;
		
		struct full_board board; 



		int possibleStatus[];

	public:
		void populate();
		void print_board();
		void add_tiles_to_board();
		
		string getId(int index){ return values[index].str; };
		int getStatus(int index){ return values[index].status; };
		void setStatus(int index, int status){ values[index].status = status; };

		// Populate the board upon initialization
		Board(){
			populate(); 
			for(int i = 0; i < 101; i++){
				values[i].status = false;
			}
			
		}
		
		struct tile values[101];

		
};

#endif