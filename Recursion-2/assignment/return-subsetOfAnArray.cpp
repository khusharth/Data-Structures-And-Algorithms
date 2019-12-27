#include <iostream>
using namespace std;

int subset(int input[], int n, int output[][20]) {
    if (n==0) {
		output[0][0] = 0;
		return 1;
	}
	// int smallOutput[][20];
	int smallSize = subset(input+1, n-1, output);
	

	for(int i=0; i<smallSize;i++) {
		output[i + smallSize][0] = output[i][0] + 1;
		output[i + smallSize][1] = input[0];
		// cout<<"output: "<<output[i + smallSize][0]<<endl;
		for(int j=1; j<=output[i][0]; j++) {		
			output[i + smallSize][j+1] = output[i][j];
		}
	}
    
	return 2 * smallSize;
}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);
	cout <<"size: "<< size <<endl;

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
