#include "battleship_main.h"

struct tile values[101]; // Struct Array to hold values

void populate(){


	string number = "0"; // Number to be combined
	string letter = "A"; // Letter to be combined

	char num = '0'; // temporary use when converting from int to string
	char two = 'A';	// temporary use when converting from int to string

	for (int i = 1; i < 101; i++)
	{

		// Combines letter and number and assigns it to name in struct[i]

		values[i].str.append(letter);
		values[i].str.append(number);
		values[i].id_num = i;

		// Increments number every loop 
		int temp2 = (int)num;
		temp2++;
		num = (char)temp2;
		stringstream out2;
		out2 << num;
		out2 >> number;

		// This statement is used to increment letter values up every 10 loops and get numbers back to 0 every 10 loops
		// This is how we get A1, A2, A3, etc...

		if ((i % 10) == 0){

			int temp = (int)two; // convert temp to an int
			temp++;				 // increment up one
			two = (char)temp;	 // convert back to char --- Must use char as middleman between int and string
			stringstream out;    // stringsream to write and read from
			out << two;			 // write temp char to stringstream
			out >> letter;		 // write incremented string from stringsream to string 'letter'


			// Same as above but for numbers
			// Takes number value back to 0 to use with new letter

			int temp2 = (int)num;
			temp2 -= 10;
			num = (char)temp2;
			stringstream out2;
			out2 << num;
			out2 >> number;

		}
	}
}

void print_board(tile_t param[]){

	int count = 1; // keeps track of where to print line breaks

	for (int x = 0; x < 9; x++)
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