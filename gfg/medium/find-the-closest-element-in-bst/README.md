# find-the-closest-element-in-bst

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-12T16:27:36.345Z  

```cpp
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

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1)