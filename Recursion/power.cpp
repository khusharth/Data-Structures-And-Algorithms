#include<iostream>
using namespace std;

int power(int x, int n) {
	if(n!=0) {
		return (x * power(x, n-1));
	} else {
		return 1;
	}
}

int main() {
	int x, n;
	cout << "Enter the value for base and exponent: " << endl;
	cin >> x >> n;
	cout << power(x,n);
}
