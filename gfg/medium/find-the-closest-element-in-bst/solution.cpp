/* Structure of a Binary Search Tree node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	int ans=1e5+2;
	void fun(Node *root, int k) {
		if (!root) return; 
		ans = min(ans, abs(k - root->data));
		if (root->data<k) {
			fun(root->right, k);
		}
		else {fun(root->left, k); }
	}
	int minDiff(Node *root, int k) {
		fun(root, k);
		return ans;
	}
	
};
