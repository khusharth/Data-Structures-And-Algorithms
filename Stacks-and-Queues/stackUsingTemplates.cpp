#include<iostream>
using namespace std;
template <typename T>

class StackUsingArray {
	T *data;
	int nextIndex;		// Points to next empty index where we can insert
	int capacity;

	public:

	StackUsingArray(int totalSize) {
		data = new T[totalSize];
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
	void push(T element) {
		if(nextIndex == capacity) {
			T *newData = new T[2 * capacity];
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
	T pop() {
		if(isEmpty()) {
			cout << "Stack is Empty" << endl;
			return 0;
		// O can be used for bool, int, char, pointers .. all	
		}
		nextIndex--;
		return data[nextIndex];
	}

	T top() {
		if(isEmpty()){
			cout << "Stack is Empty" << endl;
			return 0;	
		}
		return data[nextIndex-1];
	}
};

int main() {
	StackUsingArray<char> s(4);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);
	s.push(105);		// stack full

	cout << "Top: " << s.top() << endl;
	
	cout << s.pop() <<endl;
	cout << s.pop() <<endl;
	cout << s.pop() <<endl;

	cout << "Size: "<< s.size() <<endl;
	
	cout << "isEmpty: " << s.isEmpty() <<endl;

}
