# count-number-of-edges-in-an-undirected-graph

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-27T14:54:37.504Z  

```cpp
class Solution {
  public:
    int countEdges(vector<vector<int>> &adj) {
      // code here
      int edgesCnt = 0;
      for (auto nodes : adj) {
        edgesCnt += nodes.size();
      }
      return edgesCnt >> 1;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/count-number-of-edges-in-an-undirected-graph/1)