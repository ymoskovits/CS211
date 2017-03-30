/********************************
* Name: Julian Moskovits
* Date: 9/13/2016
* Description: Prints out every possible way to place 8 queens on a chess board without any queen being able to kill another.
*	Uses a 2D Array to represent a chessboard.
********************************/

#include <iostream>
using namespace std;

int main()
{
	int count = 0;
	int b[8][8] = {0}, c = 0, r = 0;
	b[0][0] = 1;
	//Go to the next column, print if you're past the last column and go through the rows in that column if not.
	NC:
		c++;
		if (c == 8){
			goto print;
		}
		r = -1;
	//In whichever column you're in, go to the next row to see if it can hold a queen. If you've gone through all rows and couldn't, backtrack.
	NR:
		r++;
		if (r == 8){
			goto backtrack;
		}
		
		for (int i = 0; i < c; ++i) if (b[r][i] == 1) goto NR;
		for (int i = 0; i < r && i < c; ++i) if (b[r - i - 1][c - i - 1] == 1) goto NR;
		for (int i = 0; i < c && i < (7 - r); ++i) if (b[r + i + 1][c - i - 1] == 1) goto NR;
		b[r][c] = 1;
		goto NC;
	//Go to the previous column and put the queen somewhere else. The current position won't work.
	backtrack:
		c--;
		//If you've backtracked past the first column, you've already gone through all possibilities. End the program.
		if (c == -1){
			return -1;
		}
		r = 0;
		while (b[r][c] != 1){
			r++;
		}
		b[r][c] = 0;
		goto NR;
	
	print:
		for(int i = 0; i < 8; ++i){
			for(int j = 0; j < 8; ++j){
			cout << b[i][j] << "    ";
			}
			
			cout << endl << endl;
		}
		
		cout << ++count << endl << endl << endl;
	//Continue to find more solutions.
		goto backtrack;

	return 0;
}
