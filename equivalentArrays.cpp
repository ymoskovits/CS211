/****************************
* Name: Julian Moskovits
* Description: Checks to see if 2 arrays are Shift Equivalent.
*****************************/
#include <iostream>
using namespace std;

bool equivalent(int a[], int b[], int n);

int main()
{
int x[5] = {1, 2, 3, 4, 5};
int y[5] = {3, 4, 5, 1, 2};

if (equivalent(x, y, 5) == true){
	cout << "Array x and Array y are shift equivalent." << endl;
}

else {
	cout << "Array x and Array y are NOT shift equivalent." << endl;
}

	return 0;
}







bool equivalent(int a[], int b[], int n){
for (int rotation = 0; rotation < n; ++rotation){	//This loop checks if the 2 arrays are identical.  If they are not it rotates array a and tries again.

	int counter = 0;

	for (int check = 0; check < n; ++check){	//This loop compares elements of array a to the coresponding elements in array b and counts how many are equivalent.

		if (a[check] == b[check]){
			++counter;		
		}

		else {
			break;
		}
	
	}

	if (counter == n){
		return true;
	}	

	a:						//If the arrays haven't been found to be equivalent, each element of array a is shifted one position to the left.
	int temp = a[0];	

	for(int shift = 0; shift < n - 1; ++shift){
		a[shift] = a[shift + 1];
	}

	a[n - 1] = temp;
}

	return false;
}
