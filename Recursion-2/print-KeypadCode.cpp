#include<iostream>
using namespace std;

void findOutput(int num, string output) {

	if (num == 0) {
		cout << output <<endl;
		return;
	}

	string option[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

	int lastNum = num % 10;
	string keypad = option[lastNum];

	for (int i=0; i<keypad.size();i++) {
		findOutput(num / 10,  keypad[i] + output);
	}
}

void printKeypad(int num){
	string output= "";
	findOutput(num, output);
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

