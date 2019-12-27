#include <iostream>
using namespace std;


void printSubsetsOfArray(int input[], int size, int output[], int outSize) {
	if(size==0) {
		for(int i=0; i<outSize;i++) {
			cout<< output[i] <<" ";
		}
		cout<<endl;
		return;
	}
	printSubsetsOfArray(input+1, size-1, output, outSize);
	int newArray[1000];
	for(int i=0; i<outSize;i++) {
		newArray[i] = output[i];
	}
	newArray[outSize] = input[0];
	printSubsetsOfArray(input+1, size-1, newArray, outSize+1);
	
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
	int output[1000];
	printSubsetsOfArray(input, size, output, 0);
	
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}

