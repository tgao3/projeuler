//problem 16
//
//the sum of the digits of 2^1000
#include<iostream>
#include<math.h>
#include<stdint.h>
#include<vector>

using namespace std;

int main() {
	//since 2^1000 is too big a number, and biginteger doesn't work.
	//i put all the numbers into a vector, backwards
	//and used addition/carry through the vector to get 2^1000
	vector<int> number;
	vector<int>::iterator it;
	int carry_over = 0;
	uint64_t result = 0;

	number.push_back(1);
	for(int i = 0; i < 1000; i++) {
		for(it = number.begin(); it != number.end(); it++) {
			*it *= 2;
			if(carry_over) {
				*it += carry_over;
				carry_over = 0;
			}

			if(*it > 9) {
				carry_over = 1;
				*it = (*it)%10;
			} else {
				carry_over = 0;
			}
		}
		if(carry_over) {
			number.push_back(carry_over);
			carry_over = 0;
		}
	}

	//then the vector of the numbers to get the sum of 2^1000
	for(it = number.begin(); it != number.end(); it++) {
		result += *it;
	}

	cout << result << endl;
	return 0;
}
