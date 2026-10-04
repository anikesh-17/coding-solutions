# Bottom View of Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

 **Note:** If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

 **Examples :** 

```
Input: root = [1, 2, 3, 4, 5, N, 6]
    
Output: [4, 2, 5, 3, 6]
Explanation: The Green nodes represent the bottom view of below binary tree.
    

```

```
Input: root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
    
Output: [5, 10, 4, 28, 25]
Explanation: The Green nodes represent the bottom view of below binary tree.
    
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T19:49:27.158Z  

```cpp
/*
Definition for Node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int data) {
		data = data;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	vector<int> bottomView(Node *root) {
		// code here
		vector<int> ans;
		if (root == NULL)
			return ans;
		map<int, int> mpp;
		queue<pair<Node*, int>> q;
		q.push({root,0});
		while (!q.empty()) {
			auto it = q.front();
			q.pop();
			Node* node = it.first;
			int line = it.second;
			mpp[line] = node->data;
			if (node->left != nullptr)
				q.push({node->left, line - 1});
			if (node->right != nullptr)
				q.push({node->right, line + 1});
		}
		for (auto it : mpp)
			ans.push_back(it.second);
		return ans;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)