#include "../include/board.h"
#include "../include/display.h"


//Sets the status of the board based on its index and desired status
int Board::setStatus(int index, int status){ 

	values[index].status = status;
	return 0;
};

//Sets the board up to have its tile names to be assigned to A1, D3, etc.
void Board::populate(){

	string number = "1"; //Number to be combined
	string letter = "A"; //Letter to be combined

	int num = 1; //Temporary use when converting from int to string
	char two = 'A';	//Temporary use when converting from int to string

	for (int i = 1; i < 101; i++)
	{
		//Combines letter and number and assigns it to name in struct[i]
		values[i].str.append(letter);
		values[i].str.append(number);
		values[i].id_num = i;

		//Increments number every loop 
		int temp2 = num;
		temp2++;
		num = temp2;
		stringstream out2;
		out2 << num;
		out2 >> number;

		//This statement is used to increment letter values up every 10 loops and get numbers back to 0 every 10 loops
		//This is how we get A1, A2, A3, etc...

		if ((i % 10) == 0){

			int temp = (int)two; //Convert temp to an int
			temp++;				 //Increment up one
			two = (char)temp;	 //Convert back to char --- Must use char as middleman between int and string
			stringstream out;    //Stringsream to write and read from
			out << two;			 //Write temp char to stringstream
			out >> letter;		 //Write incremented string from stringsream to string 'letter'

			//Same as above but for numbers
			//Takes number value back to 0 to use with new letter

			int temp2 = num;
			temp2 -= 10;
			num = temp2;
			stringstream out2;
			out2 << num;
			out2 >> number;
		}
	}
};

//Prints the board to the screen as in Battleship
void Board::print_user_board(){

	Display out = Display();

	int count = 1; //Keeps track of where to print line breaks
	for (int x = 0; x < 10; x++)
	{
		for (int i = 0; i < 10; i++)
		{	
			stringstream ss; 
			char temp[100];
			

			if(values[count].status == 1){
				ss << "*S" ;
				ss >> temp;
				out.push_to_first_display(temp);
				memset(&temp[0], 0, sizeof(temp));
			}
			else{
				ss << values[count].str ;
				ss >> temp;
				out.push_to_first_display(temp);
				memset(&temp[0], 0, sizeof(temp));

			}
			count++;
		}
		//cout << "\n";
		out.push_to_first_display("\n");
	}

	out.push_to_first_display("---------------\n"); //Creates a buffer between the output
};

//Prints the board to the screen as in Battleship
void Board::print_computer_board(){

	Display out = Display();

	int count = 1; //Keeps track of where to print line breaks
	for (int x = 0; x < 10; x++)
	{
		for (int i = 0; i < 10; i++)
		{	
			stringstream ss; 
			char temp[100];
			
			if(values[count].status == 1){
				ss << "*S" ;
				ss >> temp;
				out.push_to_second_display(temp);
				memset(&temp[0], 0, sizeof(temp));
			}
			else if(values[count].status == 2){
				ss << "*H" ;
				ss >> temp;
				out.push_to_second_display(temp);
				memset(&temp[0], 0, sizeof(temp));
			}
			else if(values[count].status == 3){
				ss << "*M" ;
				ss >> temp;
				out.push_to_second_display(temp);
				memset(&temp[0], 0, sizeof(temp));
			}
			else{
				ss << values[count].str ;
				ss >> temp;
				out.push_to_second_display(temp);
				memset(&temp[0], 0, sizeof(temp));

			}
			count++;
		}
		//cout << "\n";
		out.push_to_second_display("\n");
	}

	out.push_to_second_display("---------------\n"); //Creates a buffer between the output
};

//Adds tiles to the board
void Board::add_tiles_to_board(){
	board.tiles = values;
	std::cout << "Added tiles to board\n";
}

/*int main(){

	//Testing the board printing method.
	Board board;
	board.print_board();

	board.setStatus(1, 1);

	cout << "\n\n";
	board.print_board();
}*/

