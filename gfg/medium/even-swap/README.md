# even-swap

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-20T13:33:56.195Z  

```cpp
class Solution {
	public:
	vector<int> lexicographicallyLargest(vector<int> &nums) {
		// code here
		int n = nums.size();
		int i = 0;
		vector<int> ans(n);
		
		while (i < n) {
			
			int j = i;
			ans[j] = nums[j];
			j++;
			
			while (j < n && ans[j - 1] % 2 == nums[j] % 2) {
				ans[j] = nums[j];
				j++;
			}
			
			sort(begin(ans) + i, begin(ans) + j, greater<int>());
			
			i = j;
		}
		
		return ans;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/even-swap/1)