#include <iostream>
using namespace std;

#include <cstring>
bool helper(char input[], int start, int end) {

	if(start<=end) {
	if (input[start] == input[end]) {
		return helper(input, start+1, end-1);
	}
	else {
		return false;
	}
	}

	return true;
}

bool checkPalindrome(char input[]) {
    
	int n = strlen(input);

  	if (n == 0 && n == 1)
	{
		return true;
	}

	int ans = helper(input, 0, n-1);
   return ans;
}


int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}


