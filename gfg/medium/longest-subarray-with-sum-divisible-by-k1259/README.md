# longest-subarray-with-sum-divisible-by-k1259

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-22T10:18:54.411Z  

```cpp
class Solution {
	public:
	int longestSubarrayDivK(vector<int>& arr, int k) {
		// code here
		unordered_map<int, int> mp;
		mp[0] = -1;
		int currSum = 0, ans = 0;
		for (int i = 0; i < arr.size(); i++) {
			currSum += arr[i];
			int rem = currSum % k;
			if (rem < 0)
				rem += k;
			
			if (mp.find(rem) == mp.end()) {
				mp[rem] = i;
			} else {
				ans = max(ans, i - mp[rem]);
			}
		}
		return ans;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1)