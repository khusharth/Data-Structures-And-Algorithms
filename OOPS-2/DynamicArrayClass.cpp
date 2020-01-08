#include<iostream>
using namespace std;

class DynamicArray {
	int *data;		// Pointer which will point to current Array
	int nextIndex;
	int capacity;	// Size of Array

	public:
	
	DynamicArray() {
		data = new int[5];	// We assume array size to 5
		nextIndex = 0;
		capacity = 5;
	}

	// To add an element to the array
	void add(int element) {
		if(nextIndex == capacity) {	// Create new Array
			int *newData = new int[2 * capacity];
			for(int i=0; i<capacity; i++) {
				newData[i] = data[i];
			}
			delete [] data;
			data = newData;	// Changing Pointer to point our new array
			capacity *= 2;
		}
		
		data[nextIndex] = element;	// Insert Element
		nextIndex++;
	}

	// To Display data according to the index user asks
	int get(int i) {
		if (i < nextIndex) {
			return data[i];
		} else {
			return -1;
		}
	}

	// To insert data at a particular index that user wants
	void add(int i, int element) {
		if (i < nextIndex) {
			data[i] = element;
		} else if (i == nextIndex){
			add(element);
		} else {
			return;
		}
	}

	// Make our own Copy constructor
	DynamicArray(DynamicArray const &d) {
	// Shallow Copy
	//this -> data = d.data;

	// Deep copy
	this -> data = new int[d.capacity];
	for (int i = 0; i < d.nextIndex; i++) {
		this -> data[i] = d.data[i];
	}
		this -> nextIndex = d.nextIndex;
		this -> capacity = d.capacity;
	}
	void print() {
		for (int i = 0; i < nextIndex; i++) {
			cout << data[i] <<" ";		
		}
		cout << endl;
	}
	
};
