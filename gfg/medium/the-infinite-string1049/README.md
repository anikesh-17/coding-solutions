# the-infinite-string1049

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-23T07:04:57.669Z  

```cpp
class Solution {
	public:
	char posInfinite(string &s, int pos) {
		long long p = pos;
		long long len = s.size();
		int steps = 0;
		while (len < p) {
			steps++;
			len = 2 * len + steps;
		}
		long long cur_len = len;
		int cur_step = steps;
		while (cur_step > 0) {
			long long prev_len = (cur_len - cur_step) / 2;
			if (p <= prev_len) {
				cur_len = prev_len;
				cur_step--;
			} else if (p <= prev_len + cur_step) {
				return '$';
			} else {
				long long offset = p - prev_len - cur_step;
				p = prev_len - offset + 1;
				cur_len = prev_len;
				cur_step--;
			}
		}
		return s[p - 1];
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/the-infinite-string1049/1)