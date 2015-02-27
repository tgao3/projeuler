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
		v.push_back(x);
		return v;
}

int main() {
	vector<int> number(1, 1);

	for(int i = 100; i > 0; i--) {
		number = addition(number, i);
	}
		
	for(vector<int>::iterator i = number.begin();
		i != number.end(); i++) {
		
		cout << *i;
	}
	cout << endl;
	return 0;
}
