# Binary Tree Right Side View

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Wix
Meta
Oracle
Yandex
Amazon

Given the `root` of a binary tree, imagine yourself standing on the  **right side**  of it, return  *the values of the nodes you can see ordered from top to bottom*.

 

 **Example 1:** 

 **Input:**  root = [1,2,3,null,5,null,4]

 **Output:**  [1,3,4]

 **Explanation:** 

 **Example 2:** 

 **Input:**  root = [1,2,3,4,null,null,null,5]

 **Output:**  [1,3,4,5]

 **Explanation:** 

 **Example 3:** 

 **Input:**  root = [1,null,3]

 **Output:**  [1,3]

 **Example 4:** 

 **Input:**  root = []

 **Output:**  []

 

 **Constraints:** 

- The number of nodes in the tree is in the range [0, 100].
- -100 <= Node.val <= 100

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 14.9 MB (beats 53.26%)  
**Submitted:** 2026-11-27T15:10:06.305Z  

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
    void recurssion(TreeNode* root, int level, vector<int>& res){
        if(root == nullptr) return;
        if(res.size() == level) res.push_back(root->val);
        recurssion(root->right, level+1, res);
        recurssion(root->left, level+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recurssion(root, 0, res);
        return res;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/binary-tree-right-side-view/)