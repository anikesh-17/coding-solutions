# sum-of-all-sub-sequences-of-a-number3437

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-15T17:23:52.762Z  

```cpp
class Solution {
	public:
	int subsequenceSum(string &s) {
		// code here
		const long long MOD = 1e9 + 7;
		
		int n = s.size();
		long long power = 1;
		long long ans = 0;
		
		// Calculate 2^(n-1) % MOD
		long long base = 2;
		int exp = n - 1;
		
		while (exp > 0) {
			if (exp & 1)
				power = (power * base) % MOD;
			
			base = (base * base) % MOD;
			exp>>= 1;
		}
		
		for (char ch : s) {
			int digit = ch - '0';
			ans = (ans + digit * power) % MOD;
		}
		
		return (int)ans;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/sum-of-all-sub-sequences-of-a-number3437/1)