#include "user.h"

bool User :: guess(){

	string desPos = "";
	cout << "Enter the coordinate of your desired carrier: ";
	cin >> desPos;

	if(isValidPosition(desPos)){

	}
	else{
		cout << "Bad choice! Choose again";
	}



	return false;
};

bool User :: isValidPosition(string desiredPose){
	if(length == 2){
		//Checks to see if there is enough room up, down, left, or right.
	}
	else if()

		//Returns an array of directions that the user can oriente the ship, based on location availabilities.
		
};



int main(){

	return 0;
}