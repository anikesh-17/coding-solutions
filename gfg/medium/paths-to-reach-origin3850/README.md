# paths-to-reach-origin3850

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-30T11:55:17.055Z  

```cpp
class Solution {
	public:
	int ways(int x, int y) {
		// code here
		vector<int>dp(y + 1, 1);
		int mod = 1e9 + 7;
		
		for (int i = 1; i <= x; i++) {
			int pre = 1;
			for (int j = 1; j <= y; j++) {
				dp[j] = (pre + dp[j])%mod;
				pre = dp[j];
			}
		}
		
		return dp[y];
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/paths-to-reach-origin3850/1)