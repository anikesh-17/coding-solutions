# good-stones--170647

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-19T15:01:49.040Z  

```cpp
class Solution {
	public:
	int goodIndices(vector<int> &arr) {
		// code here
		int n = arr.size();
		vector<int>vis(n, 0);
		vector<vector<int>> adj(n);
		queue<int>q;
		for (int i = 0; i<n; i++) {
			int dest = i + arr[i];
			if (dest<0 || dest >= n)
				q.push(i);
			else
				adj[i + arr[i]].push_back(i);
			
		}
		while (!q.empty()) {
			int idx = q.front();
			q.pop();
			vis[idx] = 1;
			for (auto it:adj[idx]) {
				q.push(it);
			}
		}
		return accumulate(vis.begin(), vis.end(), 0);
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/good-stones--170647/1)