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
	findOutput(num, "");
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

/*
--------------Coding Ninja Solution-----------------
void printKeypadHelper(int num, string output, string options[10] ) {
	if(num==0) {
	cout << output << endl;
	return;
	}

	int digit = num % 10;
	int i=0;
	while(i< options[digit].length()) {
		printKeypadHelper(num/10, options[digit][i] + output, options);
	i++;
	}
	return;
}

void printKeypad(int num) {
	string options[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	printKeypadHelper(num, "",options);
	return;
}

*/
