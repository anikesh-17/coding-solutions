# find-the-minimum-time0253

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-08T15:52:24.753Z  

```cpp
class Solution {
	public:
	int minTime(int n, int s1, int s2) {
		// code here
		long long low = 0;
		long long high = 1LL * min(s1, s2) * n;
		while (low < high) {
			long long mid = low + (high - low) / 2;
			if (mid / s1 + mid / s2 >= n)
				high = mid;
			else
				low = mid + 1;
		}
		return (int)low;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/find-the-minimum-time0253/1)