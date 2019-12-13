#include<iostream>
using namespace std;

int factorial(int n) {
	if(n==0) {
		return 1;
	}

	int smallOutput = factorial(n-1);
	int answer = n * smallOutput;
	return answer;
}

int main() {
	int n;
	cout << "\nEnter value of n: " << endl;
	cin >> n;
	cout << factorial(n);
}
