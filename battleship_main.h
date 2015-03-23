#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

typedef struct tile {
	string str;
	int id_num;
} tile_t;

int main(int argc, char *argv[1]);
void populate();
void print_board(tile_t param[]);
int main(int argc, char *argv[1]);