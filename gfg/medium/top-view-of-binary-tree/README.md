# Top View of Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

- Return the nodes from the leftmost node to the rightmost node.
- If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 

 **Examples:** 

```
Input: root = [1, 2, 3]
Output: [2, 1, 3]
Explanation: The Green colored nodes represents the top view in the below Binary tree.
 
```

```
Input: root = [10, 20, 30, 40, 60, 90, 100]
Output: [40, 20, 10, 30, 100]
Explanation: The Green colored nodes represents the top view in the below Binary tree.

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T19:53:45.252Z  

```cpp
/*
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
	vector<int> topView(Node *root) {
		// code here
		vector<int> ans;
		if (root == NULL)
			return ans;
		map<int, int> mpp;
		queue<pair<Node*, int>> q;
		q.push({root, 0});
		while (!q.empty()) {
			auto it = q.front();
			q.pop();
			Node* node = it.first;
			int line = it.second;
// 			mpp[line] = node->data;
			if(mpp.find(line) == mpp.end())
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

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1)