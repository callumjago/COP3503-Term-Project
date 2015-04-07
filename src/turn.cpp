//Win method
bool win =false;
bool lose = false;
bool gameover=false; 


//Need to pass Computer into Lose to check ship contained by Computer
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

		//Guess location 

			//checks ship, changes status to hit or miss 


		//Return hit or miss message


		if(win==true){
			//Congrats you win message
			gameover = true; 
		}
		

		if(lose==true){
			//Sorry you lose
			gameover= true;
		}

		
		if(giveup==true){
			gameover=true; 
		}


	
	


}