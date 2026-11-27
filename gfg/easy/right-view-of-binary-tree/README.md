# Right View of Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the **root** of a binary Tree. Return the right view of the binary tree. The right view of a Binary Tree is the set of nodes visible when the tree is viewed from the  **right** side.

 **Examples :** 

```
Input: root = [1, 2, 3, N, N, 4, 5]
     
Output: [1, 3, 5]

```

```
Input: root = [1, 2, 3, 4, N, N, N, N, 5]
     
Output: [1, 3, 4, 5]
```

```
Input: root = [3]    
  
Output: [3]
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-27T15:11:26.699Z  

```cpp
/*
Definition for Node
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
    void recurssion(Node *root, int level, vector<int> &res) {
      if (root == nullptr) return;
      if (res.size() == level) res.push_back(root->data);
      recurssion(root->right, level + 1, res);
      recurssion(root->left, level + 1, res);
    }
    vector<int> rightView(Node *root) {
      //  code here
      vector<int> res;
      recurssion(root, 0, res);
      return res;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1)