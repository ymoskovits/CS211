/*******************************
* Name: Julian Moskovits
* Description: Given two 2D-Arrays with each gender's rankings of the opposite gender's participants,
*		the program outputs the potential stable marriages where no man would leave his wife for a woman who would also be willing to leave her husband, and vice versa.
*
*******************************/

#include <iostream>
using namespace std;

bool ok(int[], int);

//This array will hold the woman assigned to each man. q[i] will hold the number of the woman assigned to the i'th man.
int q[3] = {0};

int c = 0, solution = 0;

//Men's preferences for the women. Cell mp[i][j] will give man i's ranking of woman j. 0 is the best ranking and 2 is the worst.
int mp[3][3] = 
	{
		{0, 2, 1},
		{0, 2, 1},
		{1, 2, 0}
	};

//Women's preferences for the men. Works the same way as "mp".
int wp[3][3] = 
	{
		{2, 1, 0},
		{0, 1, 2},
		{2, 0, 1}
	};

//We use backtracking to continue to assign women to the men in array q and check if it remains a valid solution with the addition of a new match.
int main()
{

	q[c] = 0;

//Goes to the next column in array q to find a match for man #c.
NC:
	c++;
	if(c == 3){
		goto print;
	}	
	q[c] = -1;

//Attempts to assign the next woman to man c.
NR:
	q[c]++;
	if (q[c] == 3){
		goto backtrack;
	}

	if (ok(q, c)){
		goto NC;
	}
	goto NR;

print:
	cout << "Solution #" << ++solution << ":" << endl;
	cout << "Man \t Woman" << endl;
	for (int i = 0; i < 3; ++i){
		cout << i << " \t " << q[i] << endl;
	}
	cout << endl << endl;
	
	goto backtrack;

//Go to the last man who we assigned a woman to and try to assign the next woman to him instead of the current one.
backtrack:
	c--;
	if (c == -1){
		return 0;
	}
	goto NR;
}

//Checks to see if the current arrangement is ok.
bool ok(int arr[], int col){

	for (int i = 0; i < col; ++i){
		
		//If the woman you tried to assign was already assigned to another man - return false.
		if (arr[col] == arr[i]){
			return false;
		}
	
		//If this man prefers another woman who's already assigned, check if that woman would leave her current man for this one - return false.
		if (mp[col][arr[col]] > mp[col][arr[i]]){
			if(wp[arr[i]][i] > wp[arr[i]][col]){
				return false;
			}
		}
		
		//If the woman who was assigned to this man prefers another man who already has a partner, check if that man would leave his current woman for this one - return false.
		if (wp[arr[col]][col] > wp[arr[col]][i]){
			if(mp[i][arr[i]] > mp[i][arr[col]]){
				return false;
			}
		}
	}
	return true;
}
