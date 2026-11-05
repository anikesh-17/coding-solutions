# Root Equals Sum of Children

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given the `root` of a  **binary tree**  that consists of exactly `3` nodes: the root, its left child, and its right child.

Return `true`  *if the value of the root is equal to the  **sum**  of the values of its two children, or* `false` *otherwise*.

 

 **Example 1:** 

```
Input: root = [10,4,6]
Output: true
Explanation: The values of the root, its left child, and its right child are 10, 4, and 6, respectively.
10 is equal to 4 + 6, so we return true.

```

 **Example 2:** 

```
Input: root = [5,3,1]
Output: false
Explanation: The values of the root, its left child, and its right child are 5, 3, and 1, respectively.
5 is not equal to 3 + 1, so we return false.

```

 

 **Constraints:** 

- The tree consists only of the root, its left child, and its right child.
- -100 <= Node.val <= 100

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 15.1 MB (beats 63.75%)  
**Submitted:** 2026-11-05T14:37:11.967Z  

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(root == NULL) return true;
        if (root->left == NULL && root->right == NULL) return true;
        int child = 0;
        if(root->left) child += root->left->val;
        if(root->right) child += root->right->val;
        if(root->val != child) return false;
        return checkTree(root->left) && checkTree(root->right);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/root-equals-sum-of-children/)