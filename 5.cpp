//problem 5 
//
//smallest multiple of all numbers 1-20
#include<iostream>

using namespace std;

int main() {
	int flag = 1;
	int i, result = 20;
	while(true) {
		//checks 1-19 first
		for(i = 1; i < 20; i++) {
			if(result%i) {
				//indicator that the current result
				//is not divisible by a number 1-20
				flag = 2;
				break;
			}
		}
		if(flag == 1 & !(result%20)) break;
		result++;	
		flag = 1;
	}
	cout << result << endl;
	return 0;
}
