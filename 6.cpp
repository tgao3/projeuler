//problem 6
//
//difference between sum of squares and square of sums for 1-100
#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int square = 0, sum = 0;
	for(int i = 0; i < 100; i++){
		square += pow(i, 2);
		sum += i;
	}
	sum = pow(sum += 100, 2);
	square += pow(100, 2);
	cout << sum - square << endl;
	return 0;
}
