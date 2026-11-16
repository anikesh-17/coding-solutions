# k-th-missing-element-in-natural-numbers

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-16T16:36:05.957Z  

```cpp
class Solution {
	public:
	int findKthSmall(vector<int>& arr, int k) {
		// code here
		int start = k, end = k + arr.size();
		
		while (start < end) {
			int mid = start + (end - start) / 2;
			int miss = mid;
			for (int v: arr)
				if (v <= mid)
					miss--;
			if (miss < k)
				start = mid + 1;
			else
				end = mid;
		}
		
		return start;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/k-th-missing-element-in-natural-numbers/1)