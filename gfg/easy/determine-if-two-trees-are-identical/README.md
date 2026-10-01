# Identical Trees

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two binary trees with their root nodes  **r1**  and  **r2**, return true if both of them are  **identical**, otherwise return false.
 **Note:** Two trees are identical when they have the same data and the arrangement of the data is also same.

 **Examples:** 

```
Input: r1 = [1, 2, 3, 4], r2 = [1, 2, 3, 4]

Output: true
Explanation: Trees are identical.
```

```
Input: r1 = [1, 2, 3, 4], r2 = [1, 2, 3, N, N, 4]
 
Output: false
Explanation: Trees are not identical.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-01T13:07:52.138Z  

```cpp
/*
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int x) {
		data = x;
		left = nullptr;
		right = nullptr;
	}
};
*/
class Solution {
	public:
	bool isIdentical(Node* p, Node* q) {
		// code here
		if (p == nullptr || q == nullptr) return (p == q);
		return (p->data == q->data) &&
		isIdentical(p->left, q->left) &&
		isIdentical(p->right, q->right);
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1)