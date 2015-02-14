//problem 3
//
//largest prime factor of 600851475143
#include<iostream>
#include<math.h>
#include<stdint.h>

using namespace std;

bool prime(uint64_t x) {
	for(uint64_t i = sqrt(x); i > 1; i--) 
		if(!(x%i)) return false;
	return true;
}

int main() {
	uint64_t number = 600851475143;
	uint64_t i = 2, highest = 1;
	
	while(i != number/highest) {
		if(!(number%i) && prime(i) && i > highest) 
			highest = i;
		i++;
	}	
	
	cout << highest << endl;
		
	return 0;
}
