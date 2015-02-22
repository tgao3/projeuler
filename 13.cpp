//problem 13
//
//1st 10 digits of the sum from p13.txt
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iterator>
#include<cctype>
#include<stdlib.h>

using namespace std;

//read in from file
vector<string> read_in(string name) {
	ifstream file(name);
	istream_iterator<string> start(file), end;
	vector<string> digits(start, end);

	return digits;
}

//vector<string> >> int 2d array
int ** convert(vector<string> array) {
	int ** list = new int*[100];
	int row = 0, col = 0;
	
	for(vector<string>::iterator i = array.begin();
		i != array.end(); i++) {
		
		col = 0;
		list[row] = new int[50];
		for(char c : *i) {
			if(isdigit(c)) list[row][col] = c - '0';
			col++;
		}
		row++;
		
	}
		
	return list;
}


//working backwards is alot easier than forwards
vector<int> sum_of_all(int ** array) {
	vector<int> v(50, 0);
	int col = 49, carry_over = 0;	
	
	for(int row = 0; row < 100; row++) {
		for(vector<int>::iterator i = v.begin();
			i != v.end(); i++) {
		
			//the col of the answer > 50
			//and it is not enough to just set the values
			//beyond col < 0 to zero since they havent been 
			//initialized.	
			if (col > -1) {
				*i += array[row][col];
				if(carry_over) *i += carry_over;

				if(*i > 9) {
					carry_over = 1;
					*i = (*i)%10;
				} else {
					carry_over = 0;
				}
				col--;
			} else {
				if(carry_over) *i += carry_over;
				
				if(*i > 9) {
					carry_over = 1;
					*i = (*i)%10;
				} else {
					carry_over = 0;
				}
			}
			
		}
		if(carry_over) {
			v.push_back(carry_over);
			carry_over = 0;
		}
		col = 49;
	}
	return v;
}

int main() {
	vector<string> five_hundred;
	five_hundred = read_in("p13.txt");
	
	int ** result;
	vector<int> answer;
	result = convert(five_hundred);

	answer = sum_of_all(result);
	for(int i = 0; i < 10; i++) {
		cout << answer[answer.size() - 1];
		answer.pop_back();
	}
	cout << '\n';	

	return 0;	
}
