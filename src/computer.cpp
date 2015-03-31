#include "../include/computer.h"
#include <string>
#include <stdlib.h>

bool Computer::setShip(){
	return false;
}

bool Computer::guess(){
	int num = rand() % 10 + 1;
	char let = 'A' + (rand() % 10);

	stringstream str;
	string guess;
	str << let << num;
	str >> guess;

	return false;
}

int main(){
	return 0;
}