# Maximum Level in Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a binary tree, find its maximum level (the deepest level that contains at least one node).

Root is considered at level 1.

 **Examples :** 

```
Input: root = [1, 3, 2, 4, N, N, N]

Output: 3
Explanation: The farthest leaf node is 4, which is located at level 3.
```

```
Input: root = [10, 20, 30, N, 40, N, 60, N, N, 2, N, N, N]

Output: 4
Explanation: The farthest leaf node is 2, which is located at level 4.

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-05T13:51:05.535Z  

```cpp
/* Tree Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int maxLevel(Node *root) {
        // code here
        if(root == NULL) return 0;
        int lh = maxLevel(root->left);
        int rh = maxLevel(root->right);
        return 1 + max(lh,rh);
    }
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/maximum-depth-of-binary-tree/1)