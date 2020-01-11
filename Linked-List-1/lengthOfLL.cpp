#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

// Solution ------------------
int length(Node *head) {
    
    int count = 0;
    while(head != NULL) {
        head = head-> next;
        count++;
    }
    return count;
}


void printIthNode(Node *head, int i) {
    int index = 0;
    Node *temp = head;
    while(temp != NULL) {
        if(index == i) {
            cout << temp -> data;
            return;
        }
        index++;
        temp = temp -> next;
    }
}
    
// ----------------------------

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    int pos;
    cin >> pos;
    cout << "Length is :" << length(head) <<endl;
	cout<< "Element at " << pos << ": ";
	printIthNode(head, pos);
    return 0;
}
