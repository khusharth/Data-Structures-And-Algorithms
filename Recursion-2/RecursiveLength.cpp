#include<iostream>
using namespace std;

int length(char s[]) {
	// Base case
	if (s[0] == '\0') {
		return 0;
	}
	// Recursive Call
	int smallStringLength = length(s+1);

	// Small Calculation 1 for first element
	return 1 + smallStringLength;

}

int main() {
	char str[50];
	cin >> str;

	int l = length(str);
	cout << l <<endl;
}
