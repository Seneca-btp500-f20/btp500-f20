/****************************************************************/
/*                                                              */
/*   lab 1 tester file                                          */
/*                                                              */
/*   To compile: g++ lab1.cpp lab1tester.cpp -std=c++0x         */
/*                                                              */
/*                                                              */
/****************************************************************/
#include <iostream>
using namespace std;

unsigned int factorial (unsigned int n);
double power (double base, unsigned int n);
unsigned int fibonacci (unsigned int n);

int main(void){

	int correctFactorial[13]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
	int correctPower[20]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};
	int correctFibonacci[40]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986};
	bool hasBug=false;
	for(unsigned int i=0;i<13;i++){
		int rc=factorial(i);
		if(rc !=correctFactorial[i]){
			cout << "Error: factorial (" << i << ") = " << correctFactorial[i] << endl;
			cout << "Your function returned: " << rc << endl;
			hasBug=true;
		}
	}
	for(unsigned int i=0;i<20;i++){
		double rc = power(2,i);
		if(rc !=correctPower[i]){
			cout << "Error: power(2, " << i << ") = " << correctPower[i] << endl;
			cout << "Your function returned: " << rc << endl;
			hasBug=true;
		}
	}
	for(unsigned int i=0;i<40;i++){
		unsigned int rc = fibonacci(i);
		if(rc !=correctFibonacci[i]){
			cout << "Error: fibonacci (" << i << ") = " << correctFibonacci[i] << endl;
			cout << "Your function returned: " << rc << endl;
			hasBug=true;
		}
	}
	if(hasBug){
		cout << "Your code has a bug.  please fix." << endl;
	}
	else{
		cout << "Congrats! your code is now working" << endl;
	}
}
