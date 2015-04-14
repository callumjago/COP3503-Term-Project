

//Need to pass Computer into Lose to check ship contained by Computer 
//***not sure how to do that

//USING GETISSUNK vs ISSUNK???

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
if(computer.carrier.isSunk==true)
	sunkNum++;
if(computer.battleship.isSunk==true)
	sunkNum++;
if(computer.submarine.isSunk==true)
	sunkNum++;
if(computer.cruiser.isSunk==true)
	sunkNum++;
if(computer.destroyer.isSunk==true)
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
if(user.carrier.isSunk==true)
	sunkNum++;
if(user.battleship.isSunk==true)
	sunkNum++;
if(user.submarine.isSunk==true)
	sunkNum++;
if(user.cruiser.isSunk==true)
	sunkNum++;
if(user.destroyer.isSunk==true)
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
		if(a==2||3){
			cout<<"Location already guessed, please guess again."
		}

	}
	while(user.guess()==2||3)


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
	if(computer.carrier.isSunk==false)
	{
		if(computer.carrier.getIsSunk()==true);
			computer.carrier.sinkShip();
			cout<<"You have sunk a ship!";
	}
	if(computer.battleship.isSunk==false)
	{
		if(computer.battleship.getIsSunk()==true);
			computer.battleship.sinkShip();
			cout<<"You have sunk a ship!";
	}
	if(computer.submarine.isSunk==false)
	{
		if(computer.submarine.getIsSunk()==true);
			computer.submarine.sinkShip();
			cout<<"You have sunk a ship!";
	}
	if(computer.cruiser.isSunk==false)
	{
		if(computer.cruiser.getIsSunk()==true);
			computer.cruiser.sinkShip();
			cout<<"You have sunk a ship!";
	}
	if(computer.destroyer.isSunk==false)
	{
		if(computer.destroyer.getIsSunk()==true);
			computer.destroyer.sinkShip();
			cout<<"You have sunk a ship!";
	}
	


}

void computer_hit_ship(User user; Board board_user; Computer computer; Board board_comp;){

	do{
		int b = computer.guess();
	}
	while(computer.guess()==2||3)


	if (user_computer.getStatus(a)==1){
		//run change status method
		cout<<"Hit!";
		//Need someway to check if the
	}
	else
	if (user_computer.getStatus(a)==0){
		cout<<"Miss!";
		//possible need another value in case it was guessed so it can say that the location was already guessed
	}


//Checks if it was sunk this turn or not. If it returns false that means it hasn't been sunk left
	//If it returns false, it attempts to sink it
	if(user.carrier.isSunk==false)
	{
		if(user.carrier.getIsSunk()==true);
			user.carrier.sinkShip();
			cout<<"Computer has sunk a ship!";
	}
	if(user.battleship.isSunk==false)
	{
		if(user.battleship.getIsSunk()==true);
			user.battleship.sinkShip();
			cout<<"Computer has sunk a ship!";
	}
	if(user.submarine.isSunk==false)
	{
		if(user.submarine.getIsSunk()==true);
			user.submarine.sinkShip();
			cout<<"Computer has sunk a ship!";
	}
	if(computer.cruiser.isSunk==false)
	{
		if(user.cruiser.getIsSunk()==true);
			user.cruiser.sinkShip();
			cout<<"Computer has sunk a ship!";
	}
	if(user.destroyer.isSunk==false)
	{
		if(user.destroyer.getIsSunk()==true);
			user.destroyer.sinkShip();
			cout<<"Computer has sunk a ship!";
	}
	

}



void turn(){

}

int main(){




}