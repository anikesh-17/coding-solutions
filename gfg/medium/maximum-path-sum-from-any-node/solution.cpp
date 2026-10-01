/* Structure of binary tree node
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	int findMaxSum(Node *root) {
		// code here
		int maxi = INT_MIN;
		maxPathDown(root, maxi);
		return maxi;
	}
	int maxPathDown(Node* node, int &maxi) {
		if (node == nullptr)
			return 0;
		int left = max(0, maxPathDown(node->left, maxi));
		int right = max(0, maxPathDown(node->right, maxi));
		maxi = max(maxi, left + right + node->data);
		return max(left, right) + node->data;
	}
};
