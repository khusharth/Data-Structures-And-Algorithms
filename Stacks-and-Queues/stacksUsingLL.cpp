#include<iostream>
using namespace std;
template <typename T>

class Node {
	public:
	T data;
	Node<T> *next;
	
	Node(T data) {
		this -> data = data;
		next = NULL;
	}

};

template <typename T>
class Stack {
	Node<T> *head;
	int size;	// no. of elements in stack

	public:
	Stack() {
		head = NULL;
		size = 0;
	}

	bool isEmpty() {
		return size == 0;
	}

	int getSize() {
		return size;
	}
	
	void push(T element) {
		Node<T> *newNode = new Node<T>(element);
		newNode -> next = head;
		head = newNode;
		size++;
	}

	T pop() {
	if(isEmpty()){
		return 0;
	}
	T ans = head -> data;
	Node<T> *temp = head;
	head = head -> next;
	delete temp;
	size--;
	return ans;
	}

	T top() {
	if(isEmpty()){
		return 0;
	}
	return head -> data;

	}
}; 

int main() {
	Stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);		// stack full

	cout << "Top: " << s.top() << endl;
	
	cout << s.pop() <<endl;
	cout << s.pop() <<endl;
	cout << s.pop() <<endl;

	cout << "Size: "<< s.getSize() <<endl;
	
	cout << "isEmpty: " << s.isEmpty() <<endl;

}
