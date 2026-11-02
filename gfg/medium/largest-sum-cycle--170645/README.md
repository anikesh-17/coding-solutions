# largest-sum-cycle--170645

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-02T13:00:47.003Z  

```cpp
class Solution {
	public:
	int largestSumCycle(vector<int>& edge) {
		// code here
		int n = edge.size();
		
		vector<int> indegree(n, 0);
		vector<bool> visited(n, false);
		
		for (int i = 0; i < n; i++) {
			
			if (edge[i] != -1) {
				indegree[edge[i]]++;
			}
		}
		
		queue<int> q;
		
		for (int i = 0; i < n; ++i) {
			
			if (indegree[i] == 0) {
				q.push(i);
				visited[i] = true;
			}
		}
		
		while (!q.empty()) {
			
			int u = q.front(); q.pop();
			int v = edge[u];
			
			if (v != -1) {
				
				indegree[v]--;
				
				if (indegree[v] == 0 && !visited[v]) {
					q.push(v);
					visited[v] = true;
				}
			}
		}
		
		int ans = -1;
		
		for (int i = 0; i < n; i++) {
			
			if (!visited[i]) {
				
				int sum = 0;
				int curr = i;
				
				while (!visited[curr]) {
					
					sum += curr;
					visited[curr] = true;
					
					curr = edge[curr];
				}
				
				ans = max(ans, sum);
			}
		}
		
		return ans;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/largest-sum-cycle--170645/1)