#include <iostream>
using namespace std;

int length(char input[]) {
    int len = 0;
    for(int i=0; input[i]!='\0';i++) {
        len++;
    }
    return len;
}

int power(int x, int n) {
	if(n==0) {
		return 1;
	}

	return (x * power(x, n-1));
}

int stringToNumberHelper(char input[], int size) {
    if(size == 0) {
        return 0;
    }

	int b = input[0];	// ASCII Output
	b = b - 48;		// ASCII to decimal
	
    int a = stringToNumberHelper(input+1, size-1);
		
	int finalAns = (b * power(10,size-1)) + a;     
	return finalAns;
}

int stringToNumber(char input[]) {
    // Write your code here
    int n = length(input);
	//cout<<"n: "<<n<<endl;
    int ans = stringToNumberHelper(input, n);
	return ans;
    
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
