# print-common-nodes-in-bst

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-13T16:36:31.369Z  

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
	vector<int> findCommon(Node* r1, Node* r2) {
		// code here
		unordered_set<int>st;
		Node* root = r1;
		queue<Node*>q;
		q.push(root);
		
		while (!q.empty()) {
			Node* node = q.front();
			q.pop();
			st.insert(node->data);
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		
		vector<int>ans;
		
		root = r2;
		
		q.push(root);
		
		while (!q.empty()) {
			Node* node = q.front();
			q.pop();
			if (st.find(node->data) != st.end())
				ans.push_back(node->data);
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
		
		sort(ans.begin(), ans.end());
		
		return ans;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1)