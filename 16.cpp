#include<iostream>
#include<math.h>
#include<stdint.h>
#include<boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision

int main() {
	cpp_int number;
	number = pow(2, 1000);
	cout << number << endl;

	uint64_t result;

	while(number) {
		result += number%10;
		number = number/10;
	}

	cout << result << endl;
	return 0;
}
