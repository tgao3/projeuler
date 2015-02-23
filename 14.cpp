//problem 14
//
//longest collatz sequence
#include<iostream>
#include<stdint.h>

using namespace std;

uint64_t collatz(uint64_t x) {
	uint64_t count = 1;
	while(x > 1) {
		if(x%2) {
			x = (3*x) + 1;
		} else {
			x = x/2;
		}
		count++;
	}
	return count;
}

int main() {
	uint64_t highest = 0, result = 0;	
	int answer = 0;
	for(uint64_t i = 1000000; i > 0; i--) {
		result = collatz(i);
		if(result > highest) {
			answer = i;
			highest = result;
		}
	}
	cout << answer << endl;
	return 0;
}
