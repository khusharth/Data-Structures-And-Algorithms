#include<iostream>
using namespace std;

class Node {
	public:
	int data;
	Node *next;		// Address of next Node

	Node(int data) {
		this -> data = data;
		next = NULL;
	}
};
