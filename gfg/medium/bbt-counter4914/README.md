# bbt-counter4914

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-06T07:41:50.107Z  

```cpp
class Solution {
	public:
	int countBT(int h) {
		// code here
		const int MOD = 1e9 + 7;
		if (h == 1)
			return 1;
		long long prev2 = 1, prev1 = 1;
		for (int i = 2; i <= h; i++) {
			long long curr = (prev1 * prev1 % MOD + 2 * prev1 * prev2 % MOD) % MOD;
			prev2 = prev1;
			prev1 = curr;
		}
		return (int)prev1;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/bbt-counter4914/1)