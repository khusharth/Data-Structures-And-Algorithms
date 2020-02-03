#include<vector>
using namespace std;
template <typename T>

class TreeNode {
	public:
	T data;
	vector<TreeNode<T>*> children;	// For storing address of childres like Node* in LL

	TreeNode(T data) {
		this -> data = data;
	}
};
