# path-exists

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-28T14:21:26.254Z  

```cpp
class Solution {
  public:
    bool checkPath(vector<vector<int>> &adj, int u, int v) {
      // code here
      int n = adj.size();
      vector<bool> vis(n, false);
      queue<int> q;
      q.push(u);
      vis[u] = true;
      while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == v)
          return true;
        for (int nei : adj[curr]) {
          if (!vis[nei]) {
            vis[nei] = true;
            q.push(nei);
          }
        }
      }
      return false;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/path-exists/1)