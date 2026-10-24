# trace-path3840

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-24T15:57:46.581Z  

```cpp
class Solution {
	public:
	bool isPossible(int n, int m, string& s) {
		// code here
		int lowr = 0, lowc = 0, highr = 0, highc = 0, r = 0, c = 0;
		
		for (auto it:s)
			{
			if (it == 'L')
				c--;
			if (it == 'R')
				c++;
			if (it == 'U')
				r--;
			if (it == 'D')
				r++;
			
			lowr = min(lowr, r);
			lowc = min(lowc, c);
			highr = max(highr, r);
			highc = max(highc, c);
		}
		
		if (highr - lowr<n && highc - lowc<m)
			return 1;
		return 0;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/trace-path3840/1)