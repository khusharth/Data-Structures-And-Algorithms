#include <iostream>
using namespace std;
#include <vector>
#include <queue>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};

// -------------------SOLUTION -----------------------//
TreeNode<int>* maxDataNode(TreeNode<int>* root) {

    if(root==NULL) {	// If tree Empty | Edge case Not Base Case
		return NULL;
	}
    
	TreeNode<int>* maxNode = root;
	for (int i = 0; i < root->children.size(); i++) {
		TreeNode<int>* maxChild = maxDataNode(root->children[i]);
		if (maxChild->data > maxNode->data) {
			maxNode = maxChild;
		}
	}
	return maxNode;
}
//----------------------------------------------------//
TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = maxDataNode(root);
    if(root != NULL) {
       	cout << ans -> data;
    }
}

