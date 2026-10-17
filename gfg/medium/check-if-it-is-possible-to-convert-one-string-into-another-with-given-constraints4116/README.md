# check-if-it-is-possible-to-convert-one-string-into-another-with-given-constraints4116

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-17T16:42:22.898Z  

```cpp
class Solution {
	public:
	bool isItPossible(string &s1, string &s2) {
		// code here
		if (s1.length() != s2.length())
			return false;
		int n = s1.length();
		int i = 0, j = 0;
		while (i < n && j < n) {
			while (i < n && s1[i] == '#')
				i++;
			while (j < n && s2[j] == '#')
				j++;
			if (i == n || j == n)
				break;
			if (s1[i] != s2[j])
				return false;
			if (s1[i] == 'A' && i < j)
				return false;
			if (s1[i] == 'B' && i > j)
				return false;
			i++;
			j++;
		}
		while (i < n && s1[i] == '#')
			i++;
		while (j < n && s2[j] == '#')
			j++;
		return i == n && j == n;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/check-if-it-is-possible-to-convert-one-string-into-another-with-given-constraints4116/1)