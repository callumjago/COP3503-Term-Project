//Need to pass Computer into Lose to check ship contained by Computer 
//***not sure how to do that

//USING GETISSUNK vs ISSUNK???

bool comp_carrier = false;
bool comp_battleship = false;
bool comp_submarine = false;
bool comp_cruiser = false;
bool comp_destroyer = false; 


bool user_carrier = false;
bool user_battleship = false;
bool user_submarine = false;
bool user_cruiser = false;
bool user_destroyer = false; 


//gameover boolean
bool gameover(Computer computer; User user){
	if (Lose(computer)==true){
		return true;
	}
	if (Win(user)==true){
		return true;
	}
}



//check Lose
bool Lose(Computer computer){
int sunkNum;
//!!!!!!!!!!!!!!!!!!!!------check "computer.ship"------!!!!!!!!!!!!!!!!!!!111
if(computer.carrier->getIsSunk()==true)
	sunkNum++;
if(computer.battleship->getIsSunk()==true)
	sunkNum++;
if(computer.submarine->getIsSunk()==true)
	sunkNum++;
if(computer.cruiser->getIsSunk()==true)
	sunkNum++;
if(computer.destroyer->getIsSunk()==true)
	sunkNum++;
if(sunkNum==5)
	return true;
else
	return false;
}


//Need to pass Player class into Win to check ship contained by player

//check Win
bool Win(User user){
int sunkNum;
//!!!!!!!!!!!!!!!!!!!!-----check "user.ship.get" works-------!!!!!!!!!!!!!!!!!!!
if(user.carrier->getIsSunk()==true)
	sunkNum++;
if(user.battleship->getIsSunk()==true)
	sunkNum++;
if(user.submarine->getIsSunk()==true)
	sunkNum++;
if(user.cruiser->getIsSunk()==true)
	sunkNum++;
if(user.destroyer->getIsSunk()==true)
	sunkNum++;

if(sunkNum==5){
	return true;
}
else
	return false;
	}




//-----------------------Hitting ship--------------------------
void user_hit_ship(User user; Board board_user; Computer computer; Board board_comp; ){
	
	do{
		int a = user.guess();
		if(a== -1){
			cout<<"Invalid location, please guess again."
		}
		if(board_computer.getStatus(a)==2||3){
			cout<<"Location already guessed, please guess again."
		}

	}
	while(board_computer.getStatus(a)==2||3)


	// Need a check status and change status method for board.....
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


//Checks if it was sunk this turn or not. If it returns false that means it hasn't been sunk left
	//If it returns false, it attempts to sink it
	if(comp_carrier==false)
	{
		if(computer.carrier->getIsSunk()==true){
			computer.carrier->sinkShip();
			cout<<"You have sunk a ship!";
			comp_carrier = true; 
		}
	}
	if(comp_battleship==false)
	{
		if(computer.battleship->getIsSunk()==true){
			computer.battleship->sinkShip();
			cout<<"You have sunk a ship!";
			comp_battleship = true;
		}
	}
	if(comp_submarine==false)
	{
		if(computer.submarine->getIsSunk()==true){
			computer.submarine->sinkShip();
			cout<<"You have sunk a ship!";
			comp_submarine = true;
		}
	}
	if(comp_cruiser==false)
	{
		if(computer.cruiser->getIsSunk()==true){
			computer.cruiser->sinkShip();
			cout<<"You have sunk a ship!";
			comp_cruiser = true;
		}
	}
	if(comp_destroyer==false)
	{
		if(computer.destroyer->getIsSunk()==true){
			computer.destroyer->sinkShip();
			cout<<"You have sunk a ship!";
			comp_destroyer = true; 
		}
	}
	


}

void computer_hit_ship(User user; Board board_user; Computer computer; Board board_comp;){

	do{
		int b = computer.guess();
	}
	while(==2||3)


	if (board_user.getStatus(a)==1){
		//run change status method
		cout<<"Hit!";
		//Need someway to check if the
	}
	else
	if (board_user.getStatus(a)==0){
		cout<<"Miss!";
		//possible need another value in case it was guessed so it can say that the location was already guessed
	}


//Checks if it was sunk this turn or not. If it returns false that means it hasn't been sunk left
	//If it returns false, it attempts to sink it
	if(user_carrier==false)
	{
		if(user.carrier.getIsSunk()==true){
			user.carrier.sinkShip();
			cout<<"Computer has sunk a ship!";
			user_carrier = true; 
		}
	}
	if(user_battleship==false)
	{
		if(user.battleship.getIsSunk()==true){
			user.battleship.sinkShip();
			cout<<"Computer has sunk a ship!";
			user_battleship = true; 
		}
	}
	if(user_submarine==false)
	{
		if(user.submarine.getIsSunk()==true){
			user.submarine.sinkShip();
			cout<<"Computer has sunk a ship!";
			user_submarine = true;
		}
	}
	if(user_cruiser==false)
	{
		if(user.cruiser.getIsSunk()==true){
			user.cruiser.sinkShip();
			cout<<"Computer has sunk a ship!";
			user_cruiser = true; 
		}
	}
	if(user_destroyer==false)
	{
		if(user.destroyer.getIsSunk()==true){
			user.destroyer.sinkShip();
			cout<<"Computer has sunk a ship!";
			user_destroyer = true;
		}
	}
	

}



void turn(User user; Board board_user; Computer computer; Board board_comp;){

}

int main(){




}