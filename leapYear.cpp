/*********************************
* Name: Julian Moskovits
* Description: Determines whether a certain year is a leap year.
* Note: Century years are only considered leap years if they are divisible by 400.
*********************************/
#include <iostream>
using namespace std;

bool leapYear(int y){
	bool isCenturyYear = false;
	
	if (y % 100 == 0){
		isCenturyYear = true;
	}

	if (y % 4 == 0 && (!isCenturyYear || y % 400 == 0)){
		return true;
	}

	return false;
}

int main()
{
int x = 0;

cout << "Enter a year: " ;

cin >> x;

cout << leapYear(x) << endl;
	return 0; 
}
