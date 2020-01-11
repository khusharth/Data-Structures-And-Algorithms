#include<iostream>
using namespace std;
#include"nodeClass.cpp"

void print(Node *head) {
	//Node *temp = head;	// For printing twice store head in a temp variable so as to avoid changes in head pointer

	while(head != NULL) {
		cout << head -> data << " ";
		head = head -> next;	// Updating head with next Node address
	}
	cout << endl;

	/*temp = head;
	while(temp != NULL) {
		cout << temp -> data << " " << endl;
		head = temp -> next;	// Updating head with next Node address
	}*/
}

int main() {
	Node n1(1);			// Static declaration
	Node *head = &n1;	// Saving the address of head for our reference

	Node n2(2);
	// cout << head -> data << endl;// Printing with help of head

	Node n3(3);
	Node n4(4);
	Node n5(5);

	n1.next = &n2;		// Saving address of n2 in n1
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	print(head);

	print(head);		// Head is still same as head value in main function is fixed | print makes a copy of head 
}
