//problem 10
//
//sum of all primes less than 2million
#include<iostream>
#include<math.h>
#include<stdint.h>

using namespace std;

bool prime(int x) {
	for(int i = sqrt(x); i > 1; i--) 
		if(!(x%i)) return false;
	return true;
}

int main() {
	uint64_t sum = 0;//the answer exceeded 32-bit int range.

	for(int i = 2; i < 2000000; i++) 
		if(prime(i)) sum+=i;
	cout << sum << endl;
	return 0;
}
