# Palindromic Path Queries in a Tree

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an undirected tree with `n` nodes labeled 0 to `n - 1`. This is represented by a 2D array `edges` of length `n - 1`, where `edges[i] = [ui, vi]` indicates an undirected edge between nodes `ui` and `vi`.

You are also given a string `s` of length `n` consisting of lowercase English letters, where `s[i]` represents the character assigned to node `i`.

You are also given a string array `queries`, where each `queries[i]` is either:

- "update ui c": Change the character at node ui to c. Formally, update s[ui] = c.
- "query ui vi": Determine whether the string formed by the characters on the unique path from ui to vi (inclusive) can be rearranged into a palindrome.

Return a boolean array `answer`, where `answer[j]` is `true` if the `jth` query of type `"query ui vi"​​​​​​​` can be rearranged into a  **palindrome**, and `false` otherwise.

 

 **Example 1:** 

 **Input:**  n = 3, edges = [[0,1],[1,2]], s = "aac", queries = ["query 0 2","update 1 b","query 0 2"]

 **Output:**  [true,false]

 **Explanation:** 

- "query 0 2": Path 0 → 1 → 2 gives "aac", which can be rearranged to form "aca", a palindrome. Thus, answer[0] = true.
- "update 1 b": Update node 1 to 'b', now s = "abc".
- "query 0 2": Path characters are "abc", which cannot be rearranged to form a palindrome. Thus, answer[1] = false.

Thus, `answer = [true, false]`.

 **Example 2:** 

 **Input:**  n = 4, edges = [[0,1],[0,2],[0,3]], s = "abca", queries = ["query 1 2","update 0 b","query 2 3","update 3 a","query 1 3"]

 **Output:**  [false,false,true]

 **Explanation:** 

- "query 1 2": Path 1 → 0 → 2 gives "bac", which cannot be rearranged to form a palindrome. Thus, answer[0] = false.
- "update 0 b": Update node 0 to 'b', now s = "bbca".
- "query 2 3": Path 2 → 0 → 3 gives "cba", which cannot be rearranged to form a palindrome. Thus, answer[1] = false.
- "update 3 a": Update node 3 to 'a', s = "bbca".
- "query 1 3": Path 1 → 0 → 3 gives "bba", which can be rearranged to form "bab", a palindrome. Thus, answer[2] = true.

Thus, `answer = [false, false, true]`.

 

 **Constraints:** 

- 1 <= n == s.length <= 5 * 104
- edges.length == n - 1
- edges[i] = [ui, vi]
- 0 <= ui, vi <= n - 1
- s consists of lowercase English letters.
- The input is generated such that edges represents a valid tree.
- 1 <= queries.length <= 5 * 104​​​​​​​queries[i] = "update ui c" or queries[i] = "query ui vi" 0 <= ui, vi <= n - 1 c is a lowercase English letter.

## Solution

**Language:** C++  
**Runtime:** 339 ms (beats 72.73%)  
**Memory:** 305.6 MB (beats 64.77%)  
**Submitted:** 2026-10-29T15:34:25.779Z  

```cpp
class Solution {
private:
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, val;
    int curPos;

    struct SegmentTree {
        int size;
        vector<int> tree;

        SegmentTree(int n) {
            size = n;
            tree.assign(4 * n, 0);
        }

        void update(int node, int start, int end, int idx, int val) {
            if (start == end) {
                tree[node] = val;
                return;
            }

            int mid = start + (end - start) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }

            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }

        int query(int node, int start, int end, int l, int r) {
            if (r < start || end < l) {
                return 0;
            }
            if (l <= start && end <= r) {
                return tree[node];
            }

            int mid = start + (end - start) / 2;
            return query(2 * node, start, mid, l, r) ^
                   query(2 * node + 1, mid + 1, end, l, r);
        }
    };

    int dfs(int u, int p, int d) {
        depth[u] = d;
        parent[u] = p;

        int size = 1;
        int maxChildSize = 0;

        for (int v : adj[u]) {
            if (v != p) {
                int childSize = dfs(v, u, d + 1);
                size += childSize;

                if (childSize > maxChildSize) {
                    maxChildSize = childSize;
                    heavy[u] = v;
                }
            }
        }

        return size;
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = curPos++;

        if (heavy[u] != -1) {
            decompose(heavy[u], h);
        }

        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                decompose(v, v);
            }
        }
    }

    int queryPath(int u, int v, SegmentTree& segTree) {
        int res = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                swap(u, v);
            }

            res ^= segTree.query(1, 0, n - 1, pos[head[v]], pos[v]);
            v = parent[head[v]];
        }

        if (depth[u] > depth[v]) {
            swap(u, v);
        }

        res ^= segTree.query(1, 0, n - 1, pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
                                vector<string>& queries) {
        this->n = n;
        adj.assign(n, vector<int>());

        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.assign(n, 0);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);

        dfs(0, -1, 0);

        curPos = 0;
        decompose(0, 0);

        SegmentTree segTree(n);
        val.resize(n);

        for (int i = 0; i < n; i++) {
            val[i] = 1 << (s[i] - 'a');
            segTree.update(1, 0, n - 1, pos[i], val[i]);
        }

        vector<bool> ans;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                val[u] = 1 << (c - 'a');
                segTree.update(1, 0, n - 1, pos[u], val[u]);
            } else {
                int u, v;
                ss >> u >> v;
                int mask = queryPath(u, v, segTree);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/palindromic-path-queries-in-a-tree/)