# FLOORANDCEIL - Rating 1150

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Floor and Ceil in a Binary Search Tree

You are given the root of a  **Binary Search Tree (BST)**  and an integer value  **key**. Your task is to find:

- Floor value: The node value in the BST that is the largest value less than or equal to the given key.
- Ceil value: The node value in the BST that is the smallest value greater than or equal to the given key.

If either the floor or the ceil value does not exist in the tree, return  **-1**  for that value.

### Function Declaration
- Function Name $floorAndCeil$
- Parameters $root$: The root node of the Binary Search Tree (BST). $key$: An integer value for which the floor and ceil values are to be found.
- Return Value Returns a pair (or tuple) of integers: The first value represents the floor of the key (largest value ≤ key, or -1 if it does not exist). The second value represents the ceil of the key (smallest value ≥ key, or -1 if it does not exist).
### Constraints
- $1 \leq \text{Number of Nodes} \leq 5000$
- $1 \leq \text{Node.val} \leq 10^7$
- $1 \leq \text{key} \leq 10^7$
### Input Format
- The first line contains a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input: The first line contains two space-separated integers: $N$ — the number of nodes in the BST $K$ — the key value for which the floor and ceil must be found The second line contains $N$ space-separated integers representing the level-order traversal of the BST. Use -1 (or null) to denote missing children.
### Output Format

For each test case, output on a new line two space-separated integers:

- The floor value of the key in the BST (or -1 if it does not exist)
- The ceil value of the key in the BST (or -1 if it does not exist)
### Sample 1:
Input
Output

```
3
7 13
10 5 15 2 7 12 20
7 1
10 5 15 2 7 12 20
7 25
10 5 15 2 7 12 20

```

```
12 15
-1 2
20 -1

```

### Explanation:
- For the first test case: The largest value -> 13 is 12 -> floor. The smallest value -> 13 is 15 -> ceil.
- For the second test case: No node has value -> 1, so floor is -1. The smallest node -> 1 is 2, hence ceil is 2.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-16T16:40:16.328Z  

```c_cpp
// struct TreeNode {
//     int val;
//     TreeNode *left, *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    pair<int, int> floorAndCeil(TreeNode* root, int key) {
        // write your code here 
        #define ll long long int
        ll x = -1, y = 1e10;
        auto dfs = [&](auto&& dfs, TreeNode* u) {
            if (u == nullptr) return;
            if (u->val >= key) {
                y = min((ll)u->val, y);
            }
            if (u->val <= key) {
                x = max(x, (ll)u->val);
            }
            dfs(dfs, u->left);
            dfs(dfs, u->right);
        };
        dfs(dfs, root);
        if (y == 1e10) y = -1;
        return make_pair(x, y);
    }
};

```

---

[View on CodeChef](https://www.codechef.com/problems/FLOORANDCEIL)