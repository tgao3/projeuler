#include<iostream>
#include<math.h>

using namespace std;

bool palindrome(int x) {
	int size, length, y, z;
	size = log10(x);
	length = (size + 1)/2;
	
	size-=1;
	for(int i = 0; i < length; i++) {	
		y = x%10;
		x = x/10;
		z = x / pow(10, size);
		z = z%10;
		
		size-=2;
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
			}
		}
	}
	cout << high << endl;
	return 0;
}
