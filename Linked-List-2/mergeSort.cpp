#include <iostream>
using namespace std;

class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

//-----------------SOLUTION--------------------
//Merging two Sorted linkedList function
node* mergeTwoLLs(node *head1, node *head2) {
    // Initialize fhead and fhead of the sorted LL with NULL
    node *fhead = NULL;
    node *ftail = NULL;
    
    // Check if head of LL1 or LL2 is smaller and assign fhead and ftail accordingly
    if (head1 -> data < head2 -> data) {
            fhead = head1;
            ftail = head1;
            head1 = head1 -> next;

        } else {
            fhead = head2;
            ftail = head2;
            head2= head2-> next;
        }
    
    // Sort by changing the position of tail by comparing heads
    while(head1 != NULL &&  head2 != NULL ) {
        if (head1 -> data < head2 -> data) {
            ftail -> next = head1;
            ftail = head1;
            head1 = head1 -> next;

        } else {
            ftail -> next = head2;
            ftail = head2;
            head2 = head2 -> next;
            
        }
    }
    // Just need to switch to LL which is not NULL | Rest will be automatically connected as its sorted
    if(head2!=NULL)
        ftail->next=head2;
    if(head1!=NULL)
        ftail->next=head1;
    
    return fhead;  
}

// Finding midpoint of LL
node* midpoint(node *head)
{
    //in this function 2 variables are maintained of Node type 
	//fast traverse with the gap of 1
    node *slow = head;
    node *fast = head->next;
    
    while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next ->next;
    }
    //returns the midpoint i.e slow
    return slow;
    
}

// Merge Sort Algo
node* mergeSort(node *head) {
    // Base case for recursion
  	if(head ==NULL ||head->next==NULL){
    	return head;
  	}
  	
  	// Finding the mid of LL using midpoint function
  	node* mid = midpoint(head);
  	node * temp = mid->next;
  	
  	//Breaking a single LL into two LLs one with head and other with temp as starting Node
  	mid->next = NULL;
  	
  	//Calling recursion  on two linked list and storing the heads of sorted LLs in a and b
  	node* a = mergeSort(head);
  	node* b = mergeSort(temp);
  	
  	//merging the 2 sorted LLs using mergeTwoLLs() function
  	node* fhead = mergeTwoLLs(a,b);
  	
  	//Returning of sorted LL
  	return fhead;
}



//---------------------------------------------
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    node* head=takeinput();
    head= mergeSort(head);
    print(head);
    return 0;
}

