/**********************************
* Name: Julian Moskovits
* Date: 9 / 20 / 16
* Description: Prints out all possible arrangements of nums 1-8 on a cross with no 2 consecutive numbers in adjacent boxes.
**********************************/
#include <iostream>
using namespace std;

bool validNum(int q[], int box);

//This array will tell the validNum function which adjacent boxes to check.
int nbr[8][5] = {
	{-1},
	{0, -1},
	{0, 1, -1},
	{0, 2, -1},
	{1, 2, -1},
	{1, 2, 3, 4, -1},
	{2, 3, 5, -1},
	{4, 5, 6, -1}
};

int main()
{
int q[8] = {0}, box = -1, count = 0;

//Goes to the next box in the array and tries to place a number.
NB:
	box++;
	if (box == 8){
		goto print;
	}
		
//Increments the value in the box and checks if it's a valid value.
NNUM:

//If you already tried to place an 8 and it didn't work, the current setup is not OK.
	if (q[box] == 8){
		goto BT;
	}

	q[box]++;
	if (!validNum(q, box)){
		goto NNUM;
	}
	else{
		goto NB;
	}

//Set the value of the box you're in back to zero. Go to the prevoius box and continue checking values by going to NNUM.
BT:
	q[box] = 0;
	box--;

//If you backtracked past the first box, you checked all possibilities.
	if (box == -1){
		return 0;
	}
	goto NNUM;
	
print:
	cout << ++count << endl << endl;
	cout << "    " << q[1] << "  " << q[4] << "    " << endl << endl;
	cout << " " << q[0] << "  " << q[2] << "  " << q[5] << "  " << q[7] << endl << endl;
	cout << "    " << q[3] << "  " << q[6] << "    " << endl << endl;
	cout << endl << endl;
	goto BT;

	return 0;
}



bool validNum(int q[], int box){

//Checks to see if the number you placed was already used.
	for(int i = 0; i < box; ++i){
		if (q[i] == q[box]){
			return false;
		}
	}

//Checks if the adjacent boxes have a consecutive number.
	for (int i = 0; nbr[box][i] != -1 ; ++i){
		if (abs(q[box] - q[nbr[box][i]]) == 1){
			return false;
		}
	}
	return true;
}
