#include<iostream>
using namespace std;

bool checkAB(char input[]) {
	// Write your code here
	if (input[0]=='\0') {
		cout<<"at last"<<endl;
		return true;
	}
	
	if (input[0]=='a') {
		cout<<"a "<<endl;
		if (input[1]=='a' || (input[1]=='b' && input[2]=='b')) {
			cout<<"a in r "<<endl;
			return checkAB(input + 1);
		}
		else if (input[1]=='\0' ) {
			cout<<"1 a"<<endl;
			return true;
		}
		else {
			cout<<"a f"<<endl;
			return false;
		}
	}

	else if (input[0]=='b') {
		if(input[1]=='b' && input[2]=='a') {
			cout<<"input1: "<<input<<endl;
			cout<<"bb a"<<endl;
			return checkAB(input + 2);
		}
		
		else if (input[1]=='b' && input[2]=='\0') {
			cout<<"input2: "<<input<<endl;
			cout<<"bb NULL"<<endl;
			return true;
			
		}
		else {
			cout<<"bb f "<<endl;
			return false;
		}
	}

	else {
		return false;
	}

}

int main() {
	char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
} 
