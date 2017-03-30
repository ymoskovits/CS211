/****************************
* Name: Julian Moskovits
* Description: This program recursively solves the Towers of Hanoi problem and prints out a list of moves to the console.
*****************************/

#include <iostream>
using namespace std;

void shifts(int, string, string, string);

int i = 0;

int main()
{
int stack = 0;
string a = "a", b = "b", c = "c";

cout << "How big is the stack? ";
cin >> stack;

shifts(stack, a, b, c);
	return 0;
}

void shifts(int stack, string a, string b, string c){
if (stack == 1){
	cout << ++i << ". " << a << " --> " << c << endl;
}
else{
	shifts(stack - 1, a, c, b);
	cout << ++i << ". " << a << " --> " << c << endl;
	shifts(stack - 1, b, a, c);
}
	return;
}
