//Win method
string = 
bool win =false;
bool lose = false;
bool gameover=false; 


//Need to pass Computer into Lose to check ship contained by Computer 
//***not sure how to do that

void Lose(){
int sunkNum;
if(carrier.getIsSunk()==true)
	sunkNum++;
if(battleship.getIsSunk()==true)
	sunkNum++;
if(submarine.getIsSunk()==true)
	sunkNum++;
if(cruiser.getIsSunk()==true)
	sunkNum++;
if(destroyer.getIsSunk()==true)
	sunkNum++;
if(sunkNum==5)
	lose=true;
else
	win=false;
}


//Need to pass Player class into Win to check ship contained by player
void Win(){
int sunkNum;
if(carrier.getIsSunk()==true)
	sunkNum++;
if(battleship.getIsSunk()==true)
	sunkNum++;
if(submarine.getIsSunk()==true)
	sunkNum++;
if(cruiser.getIsSunk()==true)
	sunkNum++;
if(destroyer.getIsSunk()==true)
	sunkNum++;

if(sunkNum==5)
	win=true;
else
	win=false;
	}



int main() {
	

	while(gameover!=true)

	//%%%%%%%%%%%%%%%%%%%%%__USER__%%%%%%%%%%%%%%%%%%%%%%%%%%

	//-------------------Guess location----------------------

		//User.guess

	//-------------Changes status to hit or miss------------- 

	//-------------check if ship hit is sunk-----------------
	Win();
	if(win==true){
			cout<<"Congrats! You won!";
			//Congrats you win message
			gameover = true; 
			return 0;
		}
		

//*******I need to find a way to make sure that in win scenario, computer doesnt get turn



	//%%%%%%%%%%%%%%%%%%%__COMPUTER__%%%%%%%%%%%%%%%%%%%%%%%%

	//--------------------Guess Location-------------------

		//Computer.guess
	
	//-------------Changes status to hit or miss---------------

	//-------------check if ship hit is sunk-------------------

		 //Access specific location on ship, changes it to 1 or 0 


	Lose();
	if(lose==true){
			cout<<"You lost."
			gameover= true;
			return 0;
		}

		

//Resign option and "would you like to play again" option in sim file


}