//problem 7
//
//find 10001st prime number
#include<iostream>

using namespace std;

bool prime(int x) {
	for(int i = 2; i < x; i++) 
		if(!(x%i)) return false;
	return true;
}

int main() {
	int result, i = 2, count = 0;
	
	while(count != 10001) {
		if(prime(i)) count++;
		i++;
	}
	result = i - 1;
	cout << result << endl;
	return 0;	
}
