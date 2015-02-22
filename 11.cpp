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
	istringstream isstream;
	vector<vector<string>> number(20, vector<string>(20));
	string temp;
	int iter = 0;

	for(string s : name) {
		isstream.str(s);
		cout << s << ' ';
		while(getline(isstream, temp, ' ')){
		//	cout << isstream.str() << endl;
		//	cout << "here" << endl;
		//	cout << temp << endl;
		//	number[iter].push_back(temp);
		//	cout << "iterere" << endl;
		//	temp.clear();
		}
		iter++;
	}

}

//finding the product
//only need to check 4 directions: right, down-right, down, and up-right
//checking up, up-left, and left would be repetitive
//
//direction parameter: 0 for right, 1 for down-right, 2 for down, 3 for up-right
int calculate(int ** array, int row, int col, int direction) {
}


int main() {
	vector<string> grid;
	
	grid = read_digits("p11.txt");
	
	int ** numbers;
	numbers = string_to_int(grid);
	return 0;
}
