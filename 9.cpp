//problem 9
//
//only 1 pythagorean triplet(a^2 + b^2 = c^2) a + b + c = 1000, find product: abc
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

int pythagorean(int x, int y, int z) {

	if(x > y || x > z || y > z) return 0;
	
	if((x + y + z) != 1000) return 0;
	
	int a, b, c;
	a = pow(x, 2);
	b = pow(y, 2);
	c = pow(z, 2);
	
	if((a + b) == c) return x*y*z;
	
	return 0;	
}

//for a < b < c && a + b + c = 1000, a < 333, 2 < b < 499, 335 < c < 997
int main() {
	int product = 0;

	for(int a = 1; a < 333; a++) {
		for(int b  = 2; b < 499; b++) {
			for(int c = 335; c < 997; c++) {
				product = pythagorean(a, b, c);
				if(product) {
					cout << product << endl;
					exit(EXIT_SUCCESS);
				}
			}
		}
	}
	
	return 0;
}
