# minimize-the-difference

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-26T11:00:42.037Z  

```cpp
class Solution {
	public:
	int minDiff(int k, vector<int> &arr) {
		// code here
		if (k >= arr.size()) {return 0; }
		map<int, int>mp;
		for (int i = k; i<arr.size(); i++) {
			mp[arr[i]]++;
		}
		int ans = mp.rbegin()->first - mp.begin()->first;
		for (int i = 0, j = k; j<arr.size(); j++, i++) {
			mp[arr[i]]++;
			if (mp[arr[j]] == 1) {mp.erase(arr[j]); }
			else {mp[arr[j]]--; }
			ans = min(ans, mp.rbegin()->first - mp.begin()->first);
		}
		return ans;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/minimize-the-difference/1)