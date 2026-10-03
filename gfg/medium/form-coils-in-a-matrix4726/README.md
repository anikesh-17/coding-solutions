# Coils in Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a positive integer n, consider a 4n  *4n matrix filled with integers from 1 to (4n)*  (4n) in row-major order (left to right, top to bottom). Form two coils from the matrix:

- The first coil starts from the top-left cell (0, 0) and spirals inward.
- The second coil starts from the bottom-right cell (4n - 1, 4n - 1) and spirals inward in the opposite direction.

Return these two coils in the same order.

 **Examples:** 

```
Input: n = 1
Output: [[1, 5, 9, 13, 14, 15, 11, 7], [16, 12, 8, 4, 3, 2, 6, 10]] 
Explanation: The matrix is 
 
So, the two coils are as given in the Output.
```

```
Input: n = 2
Output:
[[1, 9, 17, 25, 33, 41, 49, 57, 58, 59, 60, 61, 62, 63, 55, 47, 39, 31, 23, 15, 14, 13, 12, 11, 19, 27, 35, 43, 44, 45, 37, 29], 
 [64, 56, 48, 40, 32, 24, 16, 8, 7, 6, 5, 4, 3, 2, 10, 18, 26, 34, 42, 50, 51, 52, 53, 54, 46, 38, 30, 22, 21, 20, 28, 36]]  
Explanation:
 

```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-03T11:49:48.184Z  

```cpp
class Solution {
	public:
	
	// code here
	bool isInside(int x, int y, int l, int r, int u, int d) {
		return x >= u && y >= l && x <= d && y <= r;
	}
	const int dirx[4] = {1, 0, -1, 0};
	const int diry[4] = {0, 1, 0, -1};
	void process(int x, int y, int l, int r, int u, int d, int dir, int n, vector<int>&curr) {
		bool moved = false;
		while (isInside(x + dirx[dir], y + diry[dir], l, r, u, d)) {
			moved = true;
			x += dirx[dir];
			y += diry[dir];
			curr.push_back(x * n + y);
		}
		if (dir%2 == 0) {
			l++, r--;
		} else u++, d--;
		if (moved)process(x, y, l, r, u, d, (dir + 1)%4, n, curr);
	}
	vector<vector<int>> formCoils(int n) {
		// code here
		int m = n* 4;
		vector<vector<int>> vec(2);
		process(-1, 1, 1, m, 0, m - 1, 0, m, vec[0]);
		process(m, m, 1, m, 0, m - 1, 2, m, vec[1]);
		return vec;
	}
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/form-coils-in-a-matrix4726/1)