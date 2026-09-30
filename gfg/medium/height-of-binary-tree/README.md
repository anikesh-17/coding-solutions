# height-of-binary-tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-30T19:18:44.007Z  

```cpp
/* Structrue of Binary Tree Node
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
    int height(Node* root) {
        // code here
        if(root == NULL) return -1;
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh, rh);
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1)