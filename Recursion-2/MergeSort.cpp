#include <iostream>
using namespace std;

void merge(int input[], int si, int ei) {
	int mid = (si+ei)/2;

	int i = si;	//Pointer for 1st array
	int j = mid+1;	//Pointer for 2nd array
	int k = si;	//Pointer for temp array

	int temp[100];	// Temp Array where result will be copied

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

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
