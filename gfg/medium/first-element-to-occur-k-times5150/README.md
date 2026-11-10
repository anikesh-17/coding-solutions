# first-element-to-occur-k-times5150

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-10T16:19:28.069Z  

```cpp
class Solution {
	public:
	int firstElementKTime(vector<int>& arr, int k) {
		// code here
		unordered_map<int, int>m;
		int n = arr.size();
		for (int val:arr)
			if ((++m[val]) == k)
				return val;
		return - 1;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1)