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

//---------------SOLUTION-----------------//

Node* insertNodeRec(Node *head, int i, int data) {
    
    if(head == NULL) {
        if(i==0){                            //For adding at last place | no node next to this node
          Node *newnode= new Node(data);
          return newnode;
        }
        else {
          return head;
        }
    }
    
    if(i == 0) {
        Node *newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
        return head;
    }
    

    // rHead = head of recursive LL    
    Node *rHead = insertNodeRec(head -> next, i - 1, data);
    head -> next = rHead; // Joining our LL and Recursive LL
    
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
    int pos, data;
    cin >> pos >> data;
    head = insertNodeRec(head, pos, data);
    print(head);
    return 0;
}
