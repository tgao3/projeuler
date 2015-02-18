//problem 11
//
//from problem 8 code right now
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
int ** result = new int*[20];
int row = 0, col = 0;
for(string s : name) {
result[row] = new int[50];
for(char c : s) {
if(isdigit(c)) result[row][col] = atoi(&c);
col++;
}
row++;
col = 0;
}
return result;
}
//finding the product
//only need to check 3 directions: right, down-right, and down
//checking up, up-left, and left would be repetitive
//
//direction parameter: 0 for right, 1 for down-right, 2 for down
int calculate(int ** array, int row, int col, int direction) {
int count = 0, product = 1;
while((row < 20) && (col < 50)) {
if(!direction) {
//check right
cout << row << col << endl;
product *= array[row][col];
col++;
}
else if(direction == 1) {
//down-right
product *= array[row][col];
row++;
col++;
}
else if(direction == 2) {
//down
product *= array[row][col];
row++;
}
count++;
if(count == 13) return product;
}
return 0;
}
int main() {
vector<string> numbers;
numbers = read_digits("p8.txt");
int ** array;
int highest = 0;
int result_r = 0, result_dr = 0, result_d = 0;
array = string_to_int(numbers);
for(int i = 0; i < 20; i++) {
for(int j = 0; j < 50; j++) {
result_r = calculate(array, i, j, 0);
// result_dr = calculate(array, i, j, 1);
// result_d = calculate(array, i, j, 2);
if(result_r > highest) highest = result_r;
// if(result_dr > highest) highest = result_dr;
// if(result_d > highest) highest = result_d;
}
}
// cout << highest << endl;
return 0;
}
