//Win method
bool win =false;
bool lose = false;
bool gameover=false; 


//Need to pass Computer into Lose to check ship contained by Computer 
//***not sure how to do that



//gameover boolean
bool gameover(Computer computer; User user){
	if (Lose(computer)==true){
		return true;
	}
	if (Win(user)==true){
		return true;
	}
}

//Lose check


bool Lose(Computer computer){
int sunkNum;
//!!!!!!!!!!!!!!!!!!!!------check "computer.ship"------!!!!!!!!!!!!!!!!!!!111
if(computer.carrier.getIsSunk()==true)
	sunkNum++;
if(computer.battleship.getIsSunk()==true)
	sunkNum++;
if(computer.submarine.getIsSunk()==true)
	sunkNum++;
if(computer.cruiser.getIsSunk()==true)
	sunkNum++;
if(computer.destroyer.getIsSunk()==true)
	sunkNum++;
if(sunkNum==5)
	return true;
else
	return false;
}


//Need to pass Player class into Win to check ship contained by player
//User user? 
bool Win(User user){
int sunkNum;
//!!!!!!!!!!!!!!!!!!!!-----check "user.ship.get" works-------!!!!!!!!!!!!!!!!!!!
if(user.carrier.getIsSunk()==true)
	sunkNum++;
if(user.battleship.getIsSunk()==true)
	sunkNum++;
if(user.submarine.getIsSunk()==true)
	sunkNum++;
if(user.cruiser.getIsSunk()==true)
	sunkNum++;
if(user.destroyer.getIsSunk()==true)
	sunkNum++;

if(sunkNum==5){
	return true;
}
else
	return false;
	}




//-----------------------Hitting ship--------------------------
void ship_hit(User user; Board board_user; Computer computer; Board board_comp; ){
	
	//!!!!!!!!!!!!!!!!!!!!!!!!!! guess methods need to return an array location and not a boolean value!!!!!!!!!!!!!!!!!!!!!
	// int a = user.guess();	

	// Need a check status and change status method for board.....
	if (board_computer.getStatus(a)== 2){
		cout<<"Location already guessed, please guess again:"
	}
	else
	if (board_computer.getStatus(a)==1){
		//run change status method
		cout<<"Hit!";
		//Need someway to check if the
	}
	else
	if (board_computer.getStatus(a)==0){
		cout<<"Miss!";
		//possible need another value in case it was guessed so it can say that the location was already guessed
	}




}



int main() {
	

	while(gameover!=true)

	//%%%%%%%%%%%%%%%%%%%%%__USER__%%%%%%%%%%%%%%%%%%%%%%%%%%

	//-------------------Guess location----------------------

		//User.guess

	//-------------Changes status to hit or miss------------- 

	//-------------check if ship hit is sunk-----------------
	

//*******I need to find a way to make sure that in win scenario, computer doesnt get turn



	//%%%%%%%%%%%%%%%%%%%__COMPUTER__%%%%%%%%%%%%%%%%%%%%%%%%

	//--------------------Guess Location-------------------

		//Computer.guess
	
	//-------------Changes status to hit or miss---------------

	//-------------check if ship hit is sunk-------------------

		 //Access specific location on ship, changes it to 1 or 0 


//Resign option and "would you like to play again" option in sim file


}