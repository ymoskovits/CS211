/*********************************
* Name: Julian Moskovits
* Description: This program solves the Towers of Hanoi problem by representing different sized elements in a stack with integers stored in a vector.
	
*********************************/

#include <iostream>
#include <vector>
using namespace std;

int main()

{
	//t is an array holding 3 int vectors.
	vector <int> t[3];
	int n = 0;
	cout << "Enter the number of rings: ";
	cin >> n;
		
		//Initialize the first vector to hold the stack of ints.	
		for (int i = n + 1; i > 0; --i){
			t[0].push_back(i);
		}
	
	//Initialize the bottom of the other 2 stacks with a placeholder.
	t[1].push_back(n + 1);
	t[2].push_back(n + 1);
	
	int from = 0, to = 1, candidate = 1, move = 0;
		//For an EVEN STACK we have to shift numbers in the opposite direction in order to end with the stack in the middle vector in the same amount of moves.
		if (n % 2 == 0){
			to = 2;
		}
		
		while(t[1].size() < n + 1){
			//Print the instructions.
			cout << "Move #" << ++move << ": Transfer ring " << candidate << " from Tower " << char(from + 65) << " to Tower " << char(to + 65) << endl;
	
			//Move the rings.
			t[to].push_back(t[from].back());
			t[from].pop_back();
			
			//Set the from var for ODD STACK.
			if (n % 2 == 1){
				if (t[(to + 1) % 3].back() < t[(to + 2) % 3].back()){
					from = (to + 1) % 3;
				}
				else{
					from = (to + 2) % 3;	
				}
			}
			
			//Set the from var for EVEN STACK.
			if (n % 2 == 0){
				if (t[(to + 2) % 3].back() < t[(to + 1) % 3].back()){
					from = (to + 2) % 3;
				}
				else{
					from = (to + 1) % 3;
				}
			}
					
			//Set the to var for ODD STACK.
			if (n % 2 == 1){
				if (t[(from + 1) % 3].back() > t[from].back()){
					to = (from + 1) % 3;
				}
				else{
					to = (from + 2) % 3; 
				}
			}
			//Set the to var for EVEN STACK.
			if (n % 2 == 0){
				if (t[(from + 2) % 3].back() > t[from].back()){
					to = (from + 2) % 3;
				}
				else{
					to = (from + 1) % 3;
				}
			}
			candidate = t[from].back();
		}
	
		return 0;
}	
