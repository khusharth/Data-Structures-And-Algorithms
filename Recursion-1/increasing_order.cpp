#include<iostream>
using namespace std;

int start = 1;
void print(int n) {
	if(n==0) {
		return;
	}

	cout << start << " ";
	start++;
	print(n-1);
	return;
}

int main() {
	int n;
	cin >> n;
	print(n);
}

