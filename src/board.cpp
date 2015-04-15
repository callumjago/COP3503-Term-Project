#include "../include/board.h"
#include "../include/display.h"



void Board::populate(){

	string number = "1"; // Number to be combined
	string letter = "A"; // Letter to be combined

	int num = 1; // temporary use when converting from int to string
	char two = 'A';	// temporary use when converting from int to string

	for (int i = 1; i < 101; i++)
	{

		// Combines letter and number and assigns it to name in struct[i]

		values[i].str.append(letter);
		values[i].str.append(number);
		values[i].id_num = i;

		// Increments number every loop 
		int temp2 = num;
		temp2++;
		num = temp2;
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

			int temp2 = num;
			temp2 -= 10;
			num = temp2;
			stringstream out2;
			out2 << num;
			out2 >> number;

		}
	}
};

void Board::print_board(){

	Display out = Display();

	int count = 1; // keeps track of where to print line breaks
	for (int x = 0; x < 10; x++)
	{


		for (int i = 0; i < 10; i++)
		{

			if(values[count].status == 1){
				cout << "S " << " ";

			}
			else if(values[count].status == 2){
				cout << "H " << " ";
			}
			else if(values[count].status == 3){
				cout << "M " << " ";
			}
			else{
				//cout << values[count].str << " ";
				stringstream ss; 
				char temp[100];
				ss << values[count].str ;
				ss >> temp;
				out.push_to_display(temp);
				memset(&temp[0], 0, sizeof(temp));
				usleep(5000);
		
			}
			count++;
		}
		//cout << "\n";
		out.push_to_display("\n");
		usleep(5000);
	}

	for (int i = 0; i < 15; ++i)
	{
		out.push_to_display("-");
		usleep(5000);
	}
	
	out.push_to_display("\n");

};

void Board::add_tiles_to_board(){
	board.tiles = values;
	std::cout << "Added tiles to board\n";
}

/*

int main(){

	//Testing the board printing method.
	Board board;
	board.print_board();

	//Testing the getId function of the board at index 1.
	cout << "The ID at position A1 is " << board.getId(1) << endl;  
	return 0;
}

*/