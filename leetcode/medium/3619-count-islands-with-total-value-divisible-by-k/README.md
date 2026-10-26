# Count Islands With Total Value Divisible by K

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an `m x n` matrix `grid` and a positive integer `k`. An  **island**  is a group of  **positive**  integers (representing land) that are  **4-directionally**  connected (horizontally or vertically).

The  **total value**  of an island is the sum of the values of all cells in the island.

Return the number of islands with a total value  **divisible by**  `k`.

 

 **Example 1:** 

 **Input:**  grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5

 **Output:**  2

 **Explanation:** 

The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.

 **Example 2:** 

 **Input:**  grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3

 **Output:**  6

 **Explanation:** 

The grid contains six islands, each with a total value that is divisible by 3.

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 1000
- 1 <= m * n <= 105
- 0 <= grid[i][j] <= 106
- 1 <= k <= 106

## Solution

**Language:** C++  
**Runtime:** 20 ms (beats 91.22%)  
**Memory:** 73.4 MB (beats 95.50%)  
**Submitted:** 2026-10-26T11:01:23.795Z  

```cpp
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        int dirs[5] = {1, 0, -1, 0, 1};  // down, left, up, right
        vector<pair<int, int>> island;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                long long total = grid[i][j];  // can reach 1e11: needs 64 bits
                grid[i][j] = 0;
                island.assign(1, {i, j});
                for (size_t h = 0; h < island.size(); h++) {  // the list grows while we walk it: a BFS queue
                    auto [x, y] = island[h];
                    for (int d = 0; d < 4; d++) {
                        int a = x + dirs[d], b = y + dirs[d + 1];
                        if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b]) {
                            total += grid[a][b];
                            grid[a][b] = 0;  // sink it so it's counted once
                            island.push_back({a, b});
                        }
                    }
                }
                ans += total % k == 0;
            }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/)