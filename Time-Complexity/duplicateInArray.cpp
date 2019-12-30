#include <iostream>
using namespace std;
int MissingNumber(int arr[], int size){
    
	int formula=0;
	formula = (size-2)*(size-1);
	formula = formula / 2;

	int sumOfArray=0;
	for(int i=0;i<size;i++){
	sumOfArray +=arr[i];
	}


	return sumOfArray - formula;

}

/*
------------------ Coding Ninja -------------------
int MissingNumber(int arr[], int size){
    
	long long sum=0;
	for(int i=0;i<size;i++){
	sum += arr[i];
	}	
	int n = size;

	int sumOfNaturalNumbers= ((n-1) *(n-2)) / 2;
	return sum - sumOfNaturalNumbers;
}
*/
int main() {
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	cout << MissingNumber(input, size);	
	
	delete [] input;

	return 0;
}
