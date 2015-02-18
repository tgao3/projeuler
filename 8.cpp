//problem 8
//
//greatest product from p8.txt of 13 numbers in a row
#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<string>
#include<cctype>
#include<stdlib.h>
#include<stdint.h>

using namespace std;

//read in the 1000-digits from file
string read_digits(string name) {
	ifstream file(name);
	string line;
	getline(file, line);

	return line;
}

//convert the vector of strings to 2d-array of ints
int * string_to_int(string name) {
	int * result = new int[1000];
	int i = 0, temp = 0;

	for(char c : name) {
		if(isdigit(c)) result[i] = atoi(&c);
		//for some reason some digits get stuck together
		//but only in pairs, never triples or more
		if(result[i] > 9) {
			temp = result[i]%10;
			result[i] = result[i]/10;
			i++;
			result[i] = temp; 
			i++;
			continue;
		}
		i++;	
	}
	return result;
}

//finding the product
uint64_t calculate(int * array, int index) {
	int count = 0;
	uint64_t product = 1;
	
	while(index < 1000) {
		product *= array[index];
		index++;
		
		count++;
		if(count == 13) return product;
	}
	return 0;
}



int main() {
	string numbers;
	
	numbers = read_digits("p8.txt");
	int * array;
	uint64_t highest = 0;
	uint64_t result_r = 0;
	
	array = string_to_int(numbers);
	for(int i = 0; i < 1000; i++) {
		result_r = calculate(array, i);
		if(result_r > highest) highest = result_r;
	}
	cout << highest << endl;
	return 0;
}
