#include <iostream>
using namespace std;

int subsetSumToK(int input[], int n, int startIndex, int output[][50], int k) {
	// Why using a startIndex?
	if (startIndex == n) {
		if(k==0) {
			output[0][0]=0;
			return 1;
		}
		else {
			return 0;
		}
	}

	int smallOutput1[1000][50], smallOutput2[1000][50];
	int size1 = subsetSumToK(input, n, startIndex+1, smallOutput1, k);
	int size2 = subsetSumToK(input, n, startIndex+1, smallOutput2, k-input[startIndex]); 
	
	int row=0;
	for (int i=0; i<size1;i++) {
		for (int j=0; j<=smallOutput1[i][0]; j++)
		{
			output[row][j] = smallOutput1[i][j];
		}
		row++;
	}

	for (int i=0; i<size2; i++) {
		output[row][0] = smallOutput2[i][0] + 1;
		output[row][1] = input[startIndex]; 
		for (int j=1; j<=smallOutput2[i][0]; j++) {	// why j=1 ??
			output[row][j+1]=smallOutput2[i][j];	// why j+1??
		}
		row++;
	}
	return row;
}

int subsetSumToK(int input[], int n, int output[][50], int k) {
	return subsetSumToK(input, n, 0, output, k);
}

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);
	cout<<"size " << size << endl;

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}


/*
int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
	if(k==0) {
		output[0][0] = 0;
		return 1;
	} else 
		return 0;

	int out1[50][50], out2[50][50];
	int size1 =subsetSumToK(input+1, n-1, out1, k);	// Not including input[0]

	int size2 = subsetSumToK(input+1, n-1, out2, k-input[0]);	// Including input[0]
	for (int i=0; i<size2; i++) {
		int last = out2[i][0];
		out2[i][last+1] = input[0];
	
		for (int j=0; j<out2[i][0]+1;j++) {
		output[i][j] = out2[i][j];		
		}
		output[i][0] += 1;
	}	

	//for(int i=0; i<size;i++)
	return size1 + size2;

}


*/


