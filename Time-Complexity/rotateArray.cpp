#include <iostream>
using namespace std;

void reverse (int arr[], int start, int end) {
	while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void Rotate(int arr[], int d, int size) {
 
	// For reversing
    int start =0;
    int end= size-1;
	reverse(arr, start, end);
    
	
	// Reversing elements from 0 to size - d -1;
	// -1 for position of last element
	int start1 = 0;
    int end1 = size-d-1;
	reverse(arr, start1, end1);
	
	// Reversing elements from size - d to last;
	int start2 = size-d;
    int end2 = size-1;
	reverse(arr, start2, end2);
}	

int main() {

	int size;
	int d;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin >> d;
    
    Rotate(input,d,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;

}

