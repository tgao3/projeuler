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
void addition(vector<int> &v, int x) {
	int carry_over = 0;
	vector<int> t(v);
	vector<int>::iterator k;

	for(int j = 0; j < x - 1; j++) {
		k = t.begin();
		for(vector<int>::iterator i = v.begin();
			i != v.end(); i++) {	
			
			*i+=carry_over;
			if(k != t.end()) {
				*i+=*k;
			} 

			if(*i > 9) {
				*i = (*i)%10;
				carry_over = 1;
			} else {
				carry_over = 0;
			}

			if(k != t.end()) k++;
			
		}	
		if(carry_over) v.push_back(carry_over);
		carry_over = 0;
	}	
}

int main() {
	vector<int> number;
	uint64_t result = 0;
	
	number.push_back(1);
	for(int i = 2; i < 101; i++) {
		addition(number, i);
	}	
	
	for(vector<int>::iterator i = number.begin();
		i != number.end(); i++) {
		cout << *i << endl;
		result += *i;
	}
	cout << result << endl;
	return 0;
}
