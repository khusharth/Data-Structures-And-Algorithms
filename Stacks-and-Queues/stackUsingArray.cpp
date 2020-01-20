#include<iostream>
using namespace std;

class StackUsingArray {
	int *data;
	int nextIndex;		// Points to next empty index where we can insert
	int capacity;

	public:

	StackUsingArray(int totalSize) {
		data = new int[totalSize];
		nextIndex = 0;
		capacity = totalSize;
	}

	// Return the number of element present in my satck
	int size() {
		return nextIndex;
	}

	bool isEmpty() {
		/*
		if(nextIndex == 0) {
			return true;
		} else {
			return false;
		}
		*/
		// if below statement is true it will return true otherwise false
		return nextIndex == 0;	
	}

	// Insert Element (Static)
	/*
	void push(int element) {
		if(nextIndex == capacity) {
			cout << "Stack is full" << endl;
			return;
		}
		data[nextIndex] = element;
		nextIndex++;
	}
	*/

	// Insert Element (Dynamic)
	void push(int element) {
		if(nextIndex == capacity) {
			int *newData = new int[2 * capacity];
			for(int i = 0; i < capacity; i++) {
				newData[i] = data[i];
			}
			capacity *= 2;
			delete [] data;
			data = newData;		// Changing the data pointer to point to newArraykmnbv
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	// Delete element
	int pop() {
		if(isEmpty()) {
			cout << "Stack is Empty" << endl;
			return -1;	
		}
		nextIndex--;
		return data[nextIndex];
	}

	int top() {
		if(isEmpty()){
			cout << "Stack is Empty" << endl;
			return -1;	
		}
		return data[nextIndex-1];
	}
};

int main() {
	StackUsingArray s(4);
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);		// stack full

	cout << "Top: " << s.top() << endl;
	
	cout << s.pop() <<endl;
	cout << s.pop() <<endl;
	cout << s.pop() <<endl;

	cout << "Size: "<< s.size() <<endl;
	
	cout << "isEmpty: " << s.isEmpty() <<endl;

}
