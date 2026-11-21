# smallest-subarray-with-sum-greater-than-x5651

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-21T15:46:40.960Z  

```cpp
class Solution {
	public:
	int smallestSubWithSum(vector<int>& arr, int x) {
		// code here
		if (accumulate(arr.begin(), arr.end(), 0) <= x) {return 0; }
		int i = 0, j = 0, sum = 0, ans = arr.size();
		while (i<arr.size()) {
			sum += arr[i++];
			while (sum>x) {ans = min(ans, i - j); sum -= arr[j++]; }
		}
		return ans;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1)