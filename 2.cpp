//problem 2 
//
#include<iostream>

using namespace std;

int fib(int i){
	if(!i) return 0;
	if(i == 1) return 1;
	return fib(i - 1) + fib(i -2);
}

int main(){
	int var = 0, i = 0;
	int sum = 0;

	while(var < 4000000) {
		var = fib(i);
		if(!(var%2)) sum += var;
		i++;
	}
	cout << sum << endl;
	return 0;
}
