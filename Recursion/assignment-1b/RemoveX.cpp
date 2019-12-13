
#include <iostream>
using namespace std;

int length(char input[]) {
    int len = 0;
    for(int i=0; input[i]!='\0'; i++) {
        len++;
    }
    return len;
}

void removeXHelper(char input[], int size) {
    if (size == 0) {
        return;
    }
    
    if(input[0] == 'x') {
        for(int i=0; i<size; i++) {
            input[i] = input[i+1];
        }
		//cout<<"input: "<<input<<endl;
    }
    
	if(input[0] == 'x') 
    	removeXHelper(input, size-1);
	else 
		removeXHelper(input+1, size-1);		    
}

void removeX(char input[]) {
    // Write your code here
    int n = length(input);
	//cout<<"n: "<<n<<endl;
    
    removeXHelper(input, n);

}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}

