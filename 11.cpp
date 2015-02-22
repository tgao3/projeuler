//problem 11
//
//greatest product of 4 adjacent numbers within p11.txt
#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<string>
#include<stdlib.h>
#include<sstream>

using namespace std;

//read in the 20x20 grid from file
vector<string> read_digits(string name) {
	ifstream file(name);
	istream_iterator<string> start(file), end;
	vector<string> digits(start, end);

	return digits;
}

//convert the vector of strings to 2d-array of ints
//need to parse the strings correctly with tokens
int ** string_to_int(vector<string> name) {
	int ** grid = new int*[20];
	for(int i = 0; i < 20; i++) {
		grid[i] = new int[20];
	}

	istringstream s_to_int;
	int row = 0, col = 0, temp;

	for(string s : name) {
		s_to_int.str(s);
		s_to_int >> temp;
		grid[row][col] = temp;
		col++;
		if(col == 20) {
			row++;
			col = 0;
		}
		s_to_int.clear();
	}
	return grid;
}

//finding the product
//only need to check 4 directions: right, down-right, down, and up-right
//checking up, up-left, and left would be repetitive
//
//direction parameter: 0 for right, 1 for down-right, 2 for down, 3 for up-right
int calculate(int ** array, int row, int col, int direction) {
		int count = 0;
		uint64_t result = 1;
		while(row > -1 && col > -1 &&
			row < 20 && col < 20) {

			if(!direction) {
				result *= array[row][col];
				col++;
			} else if(direction == 1) {
				result *= array[row][col];
				row++;
				col++;
			} else if(direction == 2) {
				result *= array[row][col];
				row++;
			} else if(direction == 3) {
				result *= array[row][col];
				row--;
				col++;
			}
			count++;
			if(count == 4) return result;
		}
	
		return 0;
}


int main() {
	vector<string> grid;
	
	grid = read_digits("p11.txt");
	
	int ** numbers;
	numbers = string_to_int(grid);

	uint64_t highest = 0;
	uint64_t r = 0, dr = 0, d = 0, ur = 0;

	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < 20; j++) {
			r = calculate(numbers, i, j, 0);
			dr = calculate(numbers, i, j, 1);
			d = calculate(numbers, i, j, 2);
			ur = calculate(numbers, i, j, 3);
	
			if(r > highest) highest = r;
			if(dr > highest) highest = dr;
			if(d > highest) highest = d;
			if(ur > highest) highest = ur;
		}
	}

	cout << highest << endl;
	return 0;
}
