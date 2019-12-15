#include<iostream>
using namespace std;

int power(int x, int n) {
	if (n==0) {
		return 1;
	}
	return (x * power(x,n-1));
}

int subs(string input, string output[]) {
	if(input.empty()) {
		output[0] = "";
		return 1;
	}

	string smallString = input.substr(1);
	int smallOutputSize = subs(smallString, output);
	for (int i=0; i<smallOutputSize; i++) {	// Ques) abc
		// 0 + 4		= 	a	+ "" -> output[4]=a
		output[i + smallOutputSize] = input[0] + output[i];  
	}
	// As we copy again all the values of smallOutputSize and append in them
	return 2 * smallOutputSize;
}

int main() {
	string input;
	cin >> input;

	int n = input.size();
	int subSize = power(2, n);
	// Made an array as we need to store more than 1 strings
	string* output = new string[subSize];
	int count = subs(input, output);
	for (int i=0; i<count; i++) {
		cout << output[i] <<endl;
	}
}
