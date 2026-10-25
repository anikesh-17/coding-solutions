# sum-of-beauty-of-all-substrings-1662962118

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-25T12:16:11.100Z  

```cpp
class Solution {
	public:
	int beautySum(string &s) {
		// code here
		int n = s.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int freq[26] = {0};
			for (int j = i; j < n; j++) {
				freq[s[j] - 'a']++;
				int mx = 0, mn = n + 1;
				for (int k = 0; k < 26; k++) {
					if (freq[k] > 0) {
						mx = max(mx, freq[k]);
						mn = min(mn, freq[k]);
					}
				}
				ans += mx - mn;
			}
		}
		return ans;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/sum-of-beauty-of-all-substrings-1662962118/1)