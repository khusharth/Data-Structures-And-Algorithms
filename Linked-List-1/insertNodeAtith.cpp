#include<iostream>
using namespace std;
#include"nodeClass.cpp"

Node* takeInput() {
	int data;
	cin >> data;
	Node *head = NULL;
	Node *tail = NULL;	// Using tail to reduce complexity from n2 to n
	while(data != -1) {
		Node *newNode = new Node(data);	// Dynamic allocation
		if(head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail -> next = newNode;
			tail = tail -> next;	// OR tail = newNode;
		}
		cin >> data;
	}
	return head;
}
void print(Node *head) {
	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;	// Updating head with next Nod addr
	}
	cout << endl;
}

Node* insertNode(Node *head, int i, int data) {
	Node *newNode = new Node(data);
	int count =  0;
	Node *temp = head;

	if (i == 0) {
		newNode -> next = head;	
		head = newNode;		// update head
		return head;
	}
	while(temp != NULL && count < i - 1) { // to reach a node prev to inserted node
		temp = temp -> next;
		count++;
	}

	if (temp != NULL) { 		// Dont execute for last Node
	Node *a = temp -> next;		// store addres of next node
	temp -> next = newNode;		// Add addr of newNode in prev node
	newNode -> next = a;		// Add addr of next node in newNode
	}
	
	return head;
}


int main() {

	Node *head = takeInput();
	print(head);
	int i, data;
	cin >> i >> data;
	head = insertNode(head, i, data);
	print(head);
	

}
