/********************************
* Name: Julian Moskovits
* Description: The "integrate" function takes a function, and 2 doubles as parameters and integrates the function between those points.
********************************/


#include <iostream>
using namespace std;

typedef double (*FUNC) (double);

double integrate(FUNC f, double a, double b){
	double sum = 0;
	for (double i = a; i < b; i += 0.0001){
		sum +=  (0.0001 * f(i));
	}
	
	return sum;
}

double line(double x){
	return x;
}

double square(double x){
	return x * x;
}	

double cube(double x){
	return x * x * x;
}

int main()
{
cout << "The integral of f(x) = x between 1 and 5 is: " << integrate(line, 1, 5) << endl;
cout << "The integral of f(x) = x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl;
cout << "The integral of f(x) = x^3 bewtween 1 and 5 is: " << integrate(cube, 1, 5) << endl;

	return 0;
}
