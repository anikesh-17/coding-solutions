# Children Sum in a Binary Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a binary tree, find if it satisfies the Children Sum Property which has the following rules

- Each non-leaf node must have a value equal to the sum of its left and right children's values.
- A NULL child is considered to have a value of 0, and all leaf nodes are considered valid by default.

 **Examples:** 

```
Input: root = [35, 20, 15, 15, 5, 10, 5]

Output: true
Explanation: Here, every node is sum of its left and right child.
```

```
Input: root = [1, 4, 3, 5]
  
Output: false
Explanation: Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-05T14:36:11.682Z  

```cpp
/* Structure of a Tree Node
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return true;
        int child = 0;
        if(root->left) child += root->left->data;
        if(root->right) child += root->right->data;
        if(root->data != child) return false;
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/children-sum-parent/1)