#include "battleship_main.h"

struct tile values[100]; // Struct Array to hold values

void populate(){


	string number = "0"; // Number to be combined
	string letter = "A"; // Letter to be combined

	char num = '0'; // temporary use when converting from int to string
	char two = 'A';	// temporary use when converting from int to string

	for (int i = 1; i < 100; i++)
	{

		// This statement is used to increment values up every 10 loops
		// This is how we get A1, A2, A3, etc...

		if ((i % 10) == 0)
		{
			int temp = (int)two; // convert temp to an int
			temp++;				 // increment up one
			two = (char)temp;	 // convert back to char --- Must use char as midleman between int and string
			stringstream out;    // stringsream to write and read from
			out << two;			 // write temp char to stringstream
			out >> letter;		 // write incremented string from stringsream to string 'letter'


			// Same as above but for numbers

			int temp2 = (int)num;
			temp2++;
			num = (char)temp2;
			stringstream out2;
			out2 << num;
			out2 >> number;

		}

		// Combines letter and number and assigns it to name in struct[i]
		values[i].str.append(letter);
		values[i].str.append(number);
		values[i].id_num = i;
	}

}

void print_board(tile_t param[]){

	int count = 0; // keeps track of where to print line breaks

	for (int i = 0; i < 10; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << param[count].str << " ";
			count++;
		}
		cout << "\n";
	}
}

int main(int argc, char *argv[1]){

	populate();
	print_board(values);

}