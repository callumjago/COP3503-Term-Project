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

		struct tile values[101]; 

		int possibleStatus[];

	public:
		void populate();
		void print_board();
		
		string getId(int index){ return values[index].str; };
		int getStatus(int index){ return values[index].status; };

		Board(){
			populate(); 
			for(int i = 0; i < 101; i++){
				values[i].status = 0;
			}
		}

		
};

#endif