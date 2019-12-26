#include<iostream>
using namespace std;

void print_subs(string input, string output) {
	if(input.length() == 0) {
		cout << output <<endl;
		return;
	}

	print_subs(input.substr(1), output);			// Not including in output
	print_subs(input.substr(1), output + input[0]);	// Including in output

}

int main() {
	string input;
	cin >> input;
	string output = "";
	print_subs(input, output);
}
