#include "computer.h"
#include "user.h"
#include "board.h"

class Turn {
private:
	bool computer_carrier, computer_battleship, computer_submarine, computer_cruiser, computer_destroyer;
	bool user_carrier, user_battleship, user_submarine, user_cruiser, user_destroyer;
public:
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

	bool gameover(Computer *computer, User *user);
	bool lose(User *user);
	bool win(Computer *computer);
	void user_hit_ship(User *user, Computer *computer, Board *board_user, Board *board_computer);
	void computer_hit_ship(User *user, Computer *computer, Board *board_user, Board *board_computer);
	void turn(User *user, Computer *computer, Board *board_user, Board *board_computer);
	void frame(User *user, Computer *computer, Board *board_user, Board *board_computer);


	friend class Player;
	friend class Ship;
};