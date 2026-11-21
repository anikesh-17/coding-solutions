# Find Subtree Sizes After Changes

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given a tree rooted at node 0 that consists of `n` nodes numbered from `0` to `n - 1`. The tree is represented by an array `parent` of size `n`, where `parent[i]` is the parent of node `i`. Since node 0 is the root, `parent[0] == -1`.

You are also given a string `s` of length `n`, where `s[i]` is the character assigned to node `i`.

We make the following changes on the tree  **one**  time  **simultaneously**  for all nodes `x` from `1` to `n - 1`:

- Find the closest node y to node x such that y is an ancestor of x, and s[x] == s[y].
- If node y does not exist, do nothing.
- Otherwise, remove the edge between x and its current parent and make node y the new parent of x by adding an edge between them.

Return an array `answer` of size `n` where `answer[i]` is the  **size**  of the subtree rooted at node `i` in the  **final**  tree.

 

Original
C++
 **Example 1:** 

 **Input:**  parent = [-1,0,0,1,1,1], s = "abaabc"

 **Output:**  [6,3,1,1,1,1]

 **Explanation:** 

The parent of node 3 will change from node 1 to node 0.

 **Example 2:** 

 **Input:**  parent = [-1,0,4,0,1], s = "abbba"

 **Output:**  [5,2,1,1,1]

 **Explanation:** 

The following changes will happen at the same time:

- The parent of node 4 will change from node 1 to node 0.
- The parent of node 2 will change from node 4 to node 1.

 

 **Constraints:** 

- n == parent.length == s.length
- 1 <= n <= 105
- 0 <= parent[i] <= n - 1 for all i >= 1.
- parent[0] == -1
- parent represents a valid tree.
- s consists only of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 398 ms (beats 64.56%)  
**Memory:** 282 MB (beats 45.57%)  
**Submitted:** 2026-11-21T15:48:03.509Z  

```cpp

class Solution {
public:
    vector<int> ans;

    void dfs(int u, vector<vector<int>>& adj, string& s,
             vector<int>& p, vector<int>& last) {
        int c = s[u] - 'a', old = last[c];

        if (u && old != -1) p[u] = old;
        last[c] = u;

        for (int v : adj[u])
            dfs(v, adj, s, p, last);

        last[c] = old;
    }

    int calc(int u, vector<vector<int>>& tree) {
        ans[u] = 1;
        for (int v : tree[u])
            ans[u] += calc(v, tree);
        return ans[u];
    }

    vector<int> findSubtreeSizes(vector<int>& p, string s) {
        int n = p.size();
        vector<vector<int>> adj(n), tree(n);

        for (int i = 1; i < n; i++)
            adj[p[i]].push_back(i);

        vector<int> last(26, -1);
        dfs(0, adj, s, p, last);

        for (int i = 1; i < n; i++)
            tree[p[i]].push_back(i);

        ans.resize(n);
        calc(0, tree);
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/find-subtree-sizes-after-changes/)