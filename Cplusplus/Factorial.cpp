#include <iostream>
using namespace std;

float factorial(float  n) {
   if(n == 0 || n == 1) {
   	 return 1;
   }
   else {
   	 return n * factorial(n-1);
   }
}
int main() {
	float number;
	while(number >= 0) {
	cout << "Enter the any number from 0 - 100" << endl;
	cin >> number;
    if(number < 0) {
    	std::cout << "Error: Number is less than 0 " << endl;

    }
    std::cout << "The factorial of " << number << " is " << factorial(number) << std::endl;

   } 
    return 0;
}
