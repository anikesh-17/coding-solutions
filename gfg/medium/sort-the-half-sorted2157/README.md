# sort-the-half-sorted2157

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-11T08:45:49.377Z  

```cpp
class Solution {
	public:
	void mergeTwoParts(vector<int>& arr) {
		// code here
		int n = arr.size();
		int first = 0, second = -1;
		vector<int>temp = arr;
		for (int i = 1; i<n; ++i) {
			if (arr[i]<arr[i - 1]) {
				second = i;
				break;
			}
		}
		if (second != -1) {
			int i = first, j = second;
			int idx = 0;
			while (i<second && j<n) {
				if (temp[i] <= temp[j]) {
					arr[idx] = temp[i++];
				}
				else
					arr[idx] = temp[j++];
				idx++;
			}
			while (i<second) {
				arr[idx++] = temp[i++];
			}
			while (j<n) {
				arr[idx++] = temp[j++];
			}
		}
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/sort-the-half-sorted2157/1)