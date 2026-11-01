# maximum-sum-subarray--143510

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-01T05:32:54.885Z  

```cpp
class Solution {
	public:
	int maximumSubarray(vector<int>& arr) {
		// code here
		int n = arr.size();
		int noSq = arr[0];
		int withSq = arr[0] * arr[0];
		int ans = max(noSq, withSq);
		for (int i = 1; i < n; i++) {
			int cur = arr[i];
			int sq = cur * cur;
			int newNo = max(cur, noSq + cur);
			int newWith = max(sq, max(noSq + sq, withSq + cur));
			noSq = newNo;
			withSq = newWith;
			ans = max(ans, max(noSq, withSq));
		}
		return ans;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/maximum-sum-subarray--143510/1)