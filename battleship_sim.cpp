#include "board.h"
#include "ship.h"


int main(int argc, char *argv[1]){

	Board temp;
	temp.print_board();

	int length;
	cout << "\nEnter ship length: "; 
	cin >> length;

	Ship test = new Ship(length);
	cout << "How long is this ship? " << test.getLength() << endl;
	cout << "Is this ship sunk? " << test.getIsSunk() << endl;
	cout << "Sink this ship! " << test.sinkShip() << endl;
	cout << "Is this ship sunk? " << test.getIsSunk() << endl << endl;

	return 0;
}