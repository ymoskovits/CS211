/**********************************
* Name: Julian Moskovits
* Date: 9/16/16
* Description:  This program uses a 1D array to represent a chess board.
*		The index represents the column number and the value stored in each element represents the row for that column where the queen is placed.
*		The program prints out all arrangements of 8 queens on a chess board where no queen is able to kill another.
		No "goto" statements are used.  Instead, function calls are implemented.
**********************************/

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void NC(int q[], int& c, int& count);

void NR(int q[], int& c, int& count);

void print(int q[], int& c, int& count);

void backtrack(int q[], int& c, int& count);

int main()
{
	int q[8], c = 0, count = 0;
	q[0] = 0;
	NC(q, c, count);
}
//Goes to the beginning of the next column, and prints if you're at the last column.
void NC(int q[], int& c, int& count){
	c++;
	if (c == 8){
		print(q, c, count);
	}
	q[c] = -1;
	NR(q, c, count);
}


//Increments the row number and tests to see if it results in a conflict.
void NR(int q[], int& c, int& count){
	q[c]++;
	if (q[c] == 8){
		backtrack(q, c, count);
	}
	
	for (int i = 0; i < c; ++i){
		//Row Test
		if (q[i] == q[c]){
			NR(q, c, count);
		}
		//Diagonal Test
		if (abs(q[c] - q[i]) == c - i){
			NR(q, c, count);
		}
	}
	NC(q, c, count);
}


//Prints out the results in a 2D grid.
void print(int q[], int &c, int& count){
	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			if (q[j] == i){
				cout << "1  ";
			}
			else{
				cout << "0  ";	
			}
		}
		cout << endl << endl;
	}
	cout << endl << ++count << endl << endl << endl;
	//Goes back to find more solutions.
	backtrack(q, c, count);
}


//Goes to the previous column to continue finding more solutions. If the previous row is off the board, you've found all solutions.
void backtrack(int q[], int& c, int& count){
	c--;
	if (c == -1){
		exit(0);
	}
	NR(q, c, count);
}

