#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[1]){
	// argc is for checking command line argument existence
	// argv is for accessing command line arguments

	// For right now this will create a 10x10 array 
	// It only fills it with numbers right now though so we need to 
	// find a way to fill it with a letter and number

	int values[10][10];
	int count = 0;

	for (int i = 0; i < 10; i++)
	{
		
		for (int j = 0; j < 10; j++)
		{
			values[i][j] = count;
			cout << values[i][j] << " ";
			count++;
		}
		cout << "\n";

	}
}