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

//--------SOLUTION---------------//
int length(Node *head) {
    if (head->next == NULL) {
        return 1;
    }	
 
	head = head -> next;
    return 1 + length(head);
    
}
//-------------------------------//

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
    cout << length(head);
    return 0;
}

