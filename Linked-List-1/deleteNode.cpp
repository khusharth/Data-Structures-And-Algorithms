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

// ---------------SOLUTION -----------------//
Node* deleteNode(Node *head, int i) {
    // Base case
    if (head == NULL) {
        return head;
    }
    
    // Our part
    if (i==0) {
        Node *temp = head;
        head = head-> next;
        delete temp;
        return head;
    }
    
    // Recursion
    head -> next = deleteNode(head -> next, i-1);
 
    return head;
}
//----------------------------------------//

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
    head = deleteNode(head, pos);
    print(head);
    return 0;
}
