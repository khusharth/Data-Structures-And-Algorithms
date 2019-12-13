#include <iostream>
using namespace std;

int length(char input[]) {
    int len = 0;
    for(int i=0; input[i]!='\0';i++) {
        len++;
    }
    return len;
}

void helper(char input[], int size) {
    if(size == 0) {
        return; 
    }
    
    if(input[0] == input[1]) {
        for(int i=size; i>0; i--) {
            input[i+1] = input[i];
        }
        input[1] = '*';
	size = size + 1;
    }
    
    helper(input+1, size-1);
}

void pairStar(char input[]) {
    // Write your code here
    int n = length(input);
	cout<<"n "<<n<<endl;
    helper(input, n);
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}

