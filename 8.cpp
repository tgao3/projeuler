//problem 8
//
//13 adjacent digits w/ greatest product from p8.txt
#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<string>
#include<cctype>
#include<stdlib.h>

using namespace std;

//read in the 1000-digits from file
vector<string> read_digits(string name) {
	ifstream file(name);
	istream_iterator<string> start(file), end;

	vector<string> digits(start, end);
	return digits;
}

//convert the vector of strings to 2d-array of ints
int ** string_to_int(vector<string> name) {
	int ** result;
	int row = 0, col = 0;

	for(string s : name) {
		for(char c : s) {
			if(isdigit(c)) {
				result[row][col] = atoi(c);
			}
			col++;
		}	
		row++;
		col = 0;
	}
	return result;
}

int main() {
	vector<string> numbers;
	
	numbers = read_digits("p8.txt");
	//testing testing
	for(string &temp : numbers) {
		cout << temp << endl;
	}
	cout << "\n\n" << endl;
		
	int ** array;
	array = string_to_int(numbers);
	
	//testing testing
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < 50; j++) {
			cout << array[i][j];
		}
		cout << endl;
	}
	return 0;
}
