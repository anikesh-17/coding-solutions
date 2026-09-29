/* Structure of Tree Node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
}; */

class Solution {
	public:
	void preOrderTraversal(Node* root, vector<int>& ans) {
		if (root == NULL)
			return;
		ans.push_back(root->data);
		preOrderTraversal(root->left, ans);
		preOrderTraversal(root->right, ans);
	}
	vector<int> preOrder(Node* root) {
		// code here
		vector<int> ans;
		preOrderTraversal(root, ans);
		return ans; 
	    
	}
};
