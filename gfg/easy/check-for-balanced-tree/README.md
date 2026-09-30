# Balanced Tree Check

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given the **root** of a binary tree, determine if it is height-balanced or not.

 **Note:**  A binary tree is considered height-balanced if the absolute difference in heights of the left and right subtrees is at most 1 for every node in the tree.

 **Examples:** 

```
Input: root = [10, 20, 30, 40, 60]

Output: true 
Explanation: The height difference between the left and right subtrees at all nodes is at most 1. Hence, the tree is balanced.
```

```
Input: root = [1, 2, 3, 4, N, N, N, 5] 

Output: false
Explanation: The height difference between the left and right subtrees at node 2 is 2, which exceeds 1. Hence, the tree is not balanced.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-30T19:57:12.010Z  

```cpp
/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    bool isBalanced(Node* root) {
        // code here
        return dfsHeight(root) != -1;
    }
    int dfsHeight(Node* root){
        if(root == NULL) return 0;
        int lh = dfsHeight(root->left);
        if(lh == -1) return -1;
        int rh = dfsHeight(root->right);
        if(rh == -1) return -1;
        if(abs(rh-lh) > 1) return -1;
        return 1 + max(lh, rh);
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1)