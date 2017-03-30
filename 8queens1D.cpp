/****************************************
* Name: Julian Moskovits
* Date: 9/15/16
* Description:  This program uses a 1D array to represent a chess board.
*		The index represents the column number and the value stored in each element represents the row for that column where a queen is placed.
*		The program prints out all arrangements of 8 queens on a chess board where no queen can kill another.
****************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int q[8], c = 0,  count = 0;
	q[0] = 0;

NC:
	//Look at the next column and print if the next column is off the board.
	c++;
	if (c == 8){
		goto print;
	}
	q[c] = -1;

NR:
	//Increment the column element's value to represent the next row and check if it causes problems.
	q[c]++;
	if (q[c] == 8){
		goto backtrack;
	}
	
	for (int i = 0; i < c; ++i){
		//Row Test
		if (q[i] == q[c]){
			goto NR;
		}
		//Diagonal Test
		if (abs(q[c] - q[i]) == c - i){
			goto NR;
		}
	}
	goto NC;

print:
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
	goto backtrack;

backtrack:
	//Look at the previous column and return if you've backtracked past the first column.
	c--;
	if (c == -1){
		return 0;
	}
	goto NR;

}
