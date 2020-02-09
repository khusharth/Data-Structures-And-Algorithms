#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#include "TreeNode.h"

// -------------------- SOLUTION ------------------------- //
void printAtLevelK(TreeNode<int>* root, int k) {
	// Edge Case
	if (root == NULL) {
		return;
	}
	
	if (k == 0) {
		cout << root->data << endl;
		return;
	}

	for (int i = 0; i < root->children.size(); i++) {
		printAtLevelK(root->children[i], k-1);
	}
}

// ------------------------------------------------------- //

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



int main() {
	int k;

	TreeNode<int>* root = takeInputLevelWise();
	printLevelWise(root);

	cout << "Enter the Level you want to Print: (STARTS FROM 0) " << endl;
	cin >> k;
	printAtLevelK(root, k);
}
