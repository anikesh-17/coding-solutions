# count-the-characters1821

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-09T16:31:06.093Z  

```cpp
class Solution {
	public:
	int getCount(string &s, int k) {
		// code here
		unordered_map<char, int> countGroup;
		
		char prevChar;
		
		int ans = 0;
		
		for (auto i : s) {
			if (prevChar != i) {
				countGroup[i]++;
				prevChar = i;
			}
		}
		
		for (auto i : countGroup) {
			if (i.second == k) {
				ans++;
			}
		}
		
		return ans;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/count-the-characters1821/1)