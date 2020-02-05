#include <iostream>
#include<queue>
using namespace std;
#include "TreeNode.h"

// Taking input Level wise Using Queue
TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root Data: "<<endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;

	pendingNodes.push(root);	// Root added in the start of queue
	while (pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front(); // Store 1st in front
		pendingNodes.pop();	// Remove 1st from queue

		cout << "Enter num children of " << front->data <<endl;
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) {
			int childData;
			cout << "Enter "<< i << "th child of" << front->data <<endl;
			cin >> childData;
			// We dont create static as it wil be lost after for loop scope
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);	// Attach to parent
			pendingNodes.push(child);	// Added in Pending Queue
		}

	}
	return root;
}

// Printing Level wise Using Queue
void printLevelWise(TreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    
    queue<TreeNode<int>*> pendingNodes;
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++) {
        // If else to eliminate , at last TreeNode
        if (i < root->children.size()-1) {
            cout << root->children[i]->data << ",";
            pendingNodes.push(root->children[i]);
        }
        else {  
            cout << root->children[i]->data;
            pendingNodes.push(root->children[i]);
        }
       
    }
    cout << endl;
    
    while(pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front(); // Store 1st in front
		pendingNodes.pop();	// Remove 1st from queue
        cout << front->data << ":";
        
         for (int i = 0; i < front->children.size(); i++) {
             if (i < front->children.size()-1) {
                 cout << front->children[i]->data << ",";
                pendingNodes.push(front->children[i]);
             }
             else {
                
                cout << front->children[i]->data;
                 pendingNodes.push(front->children[i]);
             }

         }
        cout << endl;
    }
    
}

TreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter Data: " <<endl;
	cin >> rootData;	
	TreeNode<int>* root = new TreeNode<int>(rootData);

	int n;
	cout << "Enter number of children of " << rootData << endl;
	cin >> n;
	for( int i = 0; i < n; i++) {
		TreeNode<int>* child = takeInput();
		root->children.push_back(child);
	}

	return root;
}

void printTree(TreeNode<int>* root) {
	if (root == NULL) {	// handling edge case if NULL is inputed
		return;
	}

	cout << root->data << ":";
	for (int i = 0; i < root->children.size(); i++) {
		cout << root -> children[i]->data << ",";
	}
	cout<<endl;
	for (int i = 0; i < root->children.size(); i++) {
		printTree(root->children[i]);
	}
}

int main() {
	/* MANUALLY CREATING NODES AND CONNECTING THEM TO CHILDREN
	// Creates 3 individual treeNodes
	TreeNode<int>* root = new TreeNode<int>(1);
	TreeNode<int>* node1 = new TreeNode<int>(2);
	TreeNode<int>* node2 = new TreeNode<int>(3);

	// Connect root with children
	root->children.push_back(node1);
	root->children.push_back(node2);
	printTree(root);
	*/
	TreeNode<int>* root = takeInputLevelWise();
	printLevelWise(root);
}
