#include <iostream>
#include <string>
using namespace std;

int keypad(int num, string output[]){
	string list[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	// cout<<"num "<<num<<endl;
    if (num == 0 ) {
		output[0]= "";
        return 1;
    }
    
	int lastNum = num % 10;
	int smallNumber = num / 10;
	string smallOutput[500];

    int smallCount = keypad(smallNumber, smallOutput);
	// cout<<"smallCount "<<smallCount<<endl;

    int k=0;
    string alpha = list[lastNum];
	
    for(int i=0; i<alpha.size(); i++) {

		for(int j=0; j<smallCount;j++) {

			// cout<<i<<" :"<<alpha[i]<<endl;
		    output[k] =  smallOutput[j] + alpha[i];
			// cout<<i<<" :"<<output[i]<<endl;
			k++;
		}
    }
    return k;
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

