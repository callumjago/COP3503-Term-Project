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
			string str;
			int id_num;
			int status; //Represents the possible configurations of the board: hit, miss, empty.
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

		// Populate the board upon initialization
		Board(){
			populate(); 
			for(int i = 0; i < 101; i++){
				values[i].status = 0;
			}
			
		}
		
		struct tile values[101];

		
};

#endif