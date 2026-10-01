# maximum-path-sum-from-any-node

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-01T11:57:43.253Z  

```cpp
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

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1)