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

			int *status;
		} tile_t;

		struct tile values[101]; 

	public:
		void populate();
		void print_board();
		
};