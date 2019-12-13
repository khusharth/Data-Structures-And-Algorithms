int length(char input[]) {
	int len = 0;
	for(int i=0; input[i]!='\0';i++) {
		len++;
	}
	return len;
}

bool helper(char input[], int start, int end) {

	if(input[0] == '\0' || input[1] == '\0') {
		return true;
	}
	if(start<=end) {
		return true;
	}

	if (input[start] == input[end]) {
		return helper(input, start+1, end-1);
	}
	else {
		return false;
	}
}

bool checkPalindrome(char input[]) {
	int n = length(input);
	return helper(input, 0, n-1);

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

