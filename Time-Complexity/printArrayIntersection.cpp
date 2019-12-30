#include <iostream>
using namespace std;

#include <bits/stdc++.h>

// MERGE SORT IS NOT WORKING PROPERLY?
/*
void merge(int input[], int si, int ei) {
	int size = ei - si + 1;

	int mid = (si+ei)/2;

	int i = si;	//Pointer for 1st array
	int j = mid+1;	//Pointer for 2nd array
	int k = si;	//Pointer for temp array

	int * temp = new int[size];	// Temp Array where result will be copied

	while(i<=mid && j<=ei) {
		if(input[i] < input[j]) {
			temp[k++] = input[i++];
		} else {
			temp[k++] = input[j++];
		}
	}

	// After 1 array ends and if another is left
	while(i<=mid) {
		temp[k++] = input[i++];
	}
	while(j<=ei) {
		temp[k++] = input[j++];
	}

	// We need to copy all elements to original array
	for(int i=si;i<=ei;i++) {
		input[i] = temp[i];
	}

	delete [] temp;
}

void mergeSortHelper(int input[], int si, int ei) {
	if (si>=ei) {
		return;
	}

	int mid = (si + ei) / 2;
	mergeSortHelper(input, si, mid);
	mergeSortHelper(input, mid+1, ei);

	merge(input, si, ei);
}

void mergeSort(int input[], int size){
	// Write your code here
	mergeSortHelper(input, 0, size-1);
}
*/
void intersection(int input1[], int input2[], int size1, int size2) {
   
	 sort(input1,input1+size1);
	 sort(input2,input2+size2);

	int i=0,j=0;

	while(i<size1 && j <size2)
    {
            if (input1[i] == input2[j]) {
                cout << input1[i] <<endl;
				i++;
				j++;
            }
			else {
				if (input1[i] < input2[j]) {
                	i++;
            	}
				else {
					j++;
				}					
   			}
	}

}

int main() {

	int size1,size2;

	cin>>size1;
	int *input1=new int[1+size1];	
	
	for(int i=0;i<size1;i++)
		cin>>input1[i];

	cin>>size2;
	int *input2=new int[1+size2];	
	
	for(int i=0;i<size2;i++)
		cin>>input2[i];
	
	
	intersection(input1,input2,size1,size2);

		
	return 0;
}
