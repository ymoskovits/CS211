/****************************
* Name: Julian Moskovits
* Description: Recursive exercises.
*
****************************/


#include <iostream>
#include <cstdlib>
using namespace std;

//Calculates x^n.
int exp(int x, int n){
	if (n == 1){
		return x;
	}	

	return x * exp(x, n - 1);
}


//Prints a string.
void print(char* s){
	if (*s == '\0'){
		return;
	}

	cout << *s;
	print(++s);
}


//Prints the string backwards.
void rev_print(char* s){
	if (*s == '\0'){
		return;
	}
	
	rev_print(s + 1);
	cout << *s;
}


//Prints an integer backwards.
void revPrintInt(int n){
	if (n / 10 == 0){
		cout << n % 10;
		return;
	}
	
	cout << n % 10;
	revPrintInt(n / 10);
}


//Prints an integer.
void printInt(int n){
	if (n / 10 == 0){
		cout << n % 10;
		return;
	}	

	printInt(n / 10);
	cout << n % 10;
}




int main()
{
int base = 3, expo = 4;

char str[] = "hello";

int n = 123456789;

	cout << exp(base, expo) << endl;

	print(str);	cout << endl;

	rev_print(str);	cout << endl;

	revPrintInt(n);	cout << endl;

	printInt(n);	cout << endl;



	return 0;
}
