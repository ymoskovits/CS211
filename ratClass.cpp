/*************************
* Name: Julian Moskovits
* Description: Creates a class which handles Rational Numbers.
*
****************************/

#include <iostream>
using namespace std;

class Rat{
	private:
		int n;
		int d;
	public:
		//constructors
		
		//default constructor

			Rat(){
				n = 0;
				d = 1;
			}

		//2 Parameter Constructor
			
			Rat(int i, int j){
				n = i / GCD(i, j);
				d = j / GCD(i, j);
			}

		//Conversion Constructor
	
			Rat(int i){
				n = i;
				d = 1;
			}

		//Get Functions

		int getN(){
			return n;
		}

		int getD(){
			return d;
		}

		//Set Functions
		
		void setN(int i){
			n = i / GCD(i, d);
			d = d / GCD(i, d);
		}

		void setD(int j){
			int tGCD = GCD(n, j);
			n = n / tGCD;
			d = j / tGCD;
			if(d < 0){
				d = d * -1;
				n = n * -1;
			}
		}

		//Arithmetic Operators
	
		Rat operator+ (Rat r){
			Rat t;
			t.setN(n * r.d + d * r.n);
			t.setD(d * r.d);
				return t;
		}

		Rat operator- (Rat r){
			Rat t;
			t.setN(n * r.d - d * r.n);
			t.setD(d * r.d);
				return t;
		}
		
		Rat operator* (Rat r){
			Rat t;
			t.setN(n * r.n);
			t.setD(d * r.d);
				return t;
		}
	
		Rat operator/ (Rat r){
			Rat t;
			t.setN(n * r.d);
			t.setD(d * r.n);
				return t;
		}


		int GCD(int x, int y){
			return y == 0 ? x : GCD(y, x % y);
		}
  

		
		//friend ostream& operator<<(ostream& os, Rat r);
		//friend istream& operator>>(istream& is, Rat& r);		

};


// operator<< is a friend of Rat.
ostream& operator<< (ostream& os, Rat r){
	if (r.getN() > r.getD()){
		os << r.getN()/r.getD() << " ";
		if (r.getN() % r.getD() != 0){
			 os << r.getN() % r.getD() << "/" << r.getD();
		}
	}	
	else{
		os << r.getN() << "/" << r.getD();
	}
   return os;
}




int main() {
   Rat r1(5, 2), r2(3, 2);
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2;
   r2 = r1 * r2;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2 + r1 * r2 / r1;
   r2 = r2 + r1 * r2 / r1;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   
   return 0;
}
