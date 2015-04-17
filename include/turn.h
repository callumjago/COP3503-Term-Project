#include "computer.h"
#include "user.h"
#include "board.h"

class Turn {
	friend class Player;
	friend class Ship;

	private:
		//Represents true or false values regarding if the computer's ships has been sunk or not, depending on the ship
		bool computer_carrier, computer_battleship, computer_submarine, computer_cruiser, computer_destroyer;
		
		//Represents true of false values regarding if the user's ships have been sunk or not, depending on the ship
		bool user_carrier, user_battleship, user_submarine, user_cruiser, user_destroyer;

	public:
		//Initializes all the boolean values to false to represent none of the ships have been sunk
		Turn(){
			bool computer_carrier = false;
			bool computer_battleship = false;
			bool computer_submarine = false;
			bool computer_cruiser = false;
			bool computer_destroyer = false; 

			bool user_carrier = false;
			bool user_battleship = false;
			bool user_submarine = false;
			bool user_cruiser = false;
			bool user_destroyer = false;
		}

		//True if the game is over, false otherwise
		bool gameover(Computer *computer, User *user);

		//Determines if the user has lost by checking if their ships have been sunk
		bool lose(User *user);

		//Determines if the user has won by checking if the computer's ships have been sunk
		bool win(Computer *computer);

		//Represents the user hitting a computer's ship
		void user_hit_ship(User *user, Computer *computer, Board *board_user, Board *board_computer);
		
		//Represents the computer hitting a user's ship
		void computer_hit_ship(User *user, Computer *computer, Board *board_user, Board *board_computer);
		
		//Represents a turn of the game in which each player makes a guess
		void turn(User *user, Computer *computer, Board *board_user, Board *board_computer);
		
		//Represents a frame of the game in which it is determined if the end of the game has been reached
		void frame(User *user, Computer *computer, Board *board_user, Board *board_computer);
};