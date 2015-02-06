//problem 1 
//
//find sum of multi of 3 or 5 less than 1k
#include <iostream>

using namespace std;

int main(){
	int sum = 0;
	for(int i = 1; i < 1000; i++){
		if(!(i%3) || !(i%5)){
			sum += i;
		}
	}
	cout << sum << endl;
	return 0;
}
