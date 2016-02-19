#include <iostream>
#include <math.h>
using namespace std;

void PrimeFactorization(long long x) {
 
     for(int i = 2; i <= x; i++){ //Goes through the loop to search for factors
       while(x % i == 0) { //should the factor be found 
          cout << i << endl;; //Print out the factor
          x = x / i;  //Factor becomes the next number that's being divided. 
      
     }
   }  
}

int main() {
	long long n = 0;
	cout << "Enter a number to determine it's prime factor " << endl;
	cin >> n;
	PrimeFactorization(n);
	return 0;
}
