//problem 4
//
//largest palindrome from product of 2 3-digit numbers
#include<iostream>
#include<math.h>

using namespace std;

bool palindrome(int x) {
	int size, length, y, z;
	size = log10(x);//find the number of digits within x
	length = (size + 1)/2;
	//compare one half of the number to the other half
	size-=1;
	for(int i = 0; i < length; i++) {	
		y = x%10;
		x = x/10;
		z = x / pow(10, size);
		z = z%10;
		
		size-=2;//size-=2 and not size--
		//because you are losing two digits,
		//the one in the first half of the number
		//the other in the second half of the number
		if(z != y) return false;
	}
	return true;
}

int main() {
	int result = 0, high = 0;

	for(int i = 999; i > 99; i--) {
		for(int j = 999; j > 99; j--) {
			result = i*j;
			if(palindrome(result)) {
				if(result > high) high = result;
				break;
			}
		}
	}
	cout << high << endl;
	return 0;
}
