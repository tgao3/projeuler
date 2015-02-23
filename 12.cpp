//problem 12
//
//first triangle number to have over 500 divisors
#include<iostream>
#include<stdint.h>
#include<math.h>

using namespace std;

uint64_t triangle(uint64_t x) {
	uint64_t result = 0;

	while(x != 0) {
		result += x;
		x--;
	}
	return result;			
}

int divisors(uint64_t x) {
	uint64_t i = sqrt(x);
	int count = 0;
	
	while(i != 0) {
		if(!(x%i)) count+=2;
		i--;
	}
	return count;
	
}

int main() {
	int count = 0;
	uint64_t number = 0, t = 0;
	uint64_t i = 0;

	while(count < 500) {
		number = triangle(i);
		count = divisors(number);
		i++;
	}
	cout << number << endl;
	return 0;	
}
