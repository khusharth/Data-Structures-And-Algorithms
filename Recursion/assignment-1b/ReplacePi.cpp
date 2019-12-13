#include <iostream>
using namespace std;

int lenght(char input[]) {
    int len = 0;
    for(int i=0; input[i]!='\0';i++) {
        len++;
    }
    return len;
}

void replacePiHelper(char input[], int size) {

	if(size == 0) {
		return;
	}

	cout<< "input[0]: " <<input[0]<<endl;
	cout<< "input[1]: " <<input[1]<<endl;

	if(input[0] == 'p' && input[1]=='i') {
		for(int i=size+1; i>3;i--) {
			input[i] = input[i-2];		
		}
	
		cout<<"replace: "<<input<<endl;
		input[0]='3';
		input[1]='.';
		input[2]='1';
		input[3]='4';
		size = size + 2;
	}

	replacePiHelper(input+1, size-1);

}

void replacePi(char input[]) {
	// Write your code here
	int n = lenght(input);
	cout<<"n: "<<n<<endl;
	replacePiHelper(input, n);
}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}

