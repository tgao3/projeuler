//problem 20
//
//sum of the digits in 100!
#include<iostream>
#include<stdint.h>
#include<vector>
#include<iterator>

using namespace std;

//multiplication is equal to the 1st number 
//adding to itself by the 2nd number times
//i.e. 100 * 99 = (100 + 100 + ... 98 more times)
vector<int> addition(vector<int> v, int x) {
	int carry_over = 0;
	
	for(int j = 0; j < x; j++) {
		for(vector<int>::iterator i = v.begin();
			i != v.end(); i++) {	
			
			*i+=carry_over;
			*i+=*i;

			if(*i > 9) {
				*i = (*i)%10;
				carry_over = 1;
			} else {
				carry_over = 0;
			}
			
		}	
		if(carry_over) v.push_back(carry_over);
		carry_over = 0;
	}	
	return v;
}

int main() {
	vector<int> number(1, 1);
	uint64_t result = 0;
	
	for(int i = 0; i < 101; i++) {
		number = addition(number, i);
	}	
	
	for(vector<int>::iterator i = number.begin();
		i != number.end(); i++) {
		//cout << *i << endl;
		result += *i;
	}
	cout << result << endl;
	return 0;
}
