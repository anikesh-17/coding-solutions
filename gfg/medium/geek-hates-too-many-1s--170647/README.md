# geek-hates-too-many-1s--170647

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-15T12:47:45.007Z  

```cpp
class Solution {
	public:
	int maxValue(int n) {
		// code here
		for (int i = 30; i >= 2; i--)
			{
			int mask1 = 1 << i;
			int mask2 = 1 << (i - 1);
			int mask3 = 1 << (i - 2);
			
			if ((mask1&n) && (mask2&n) && (mask3&n)) {
				n = (n^mask3);
			}
		}
		return n;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/geek-hates-too-many-1s--170647/1)