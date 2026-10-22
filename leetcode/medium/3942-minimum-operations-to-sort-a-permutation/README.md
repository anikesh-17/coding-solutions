# Minimum Operations to Sort a Permutation

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` of length `n`, where `nums` is a permutation of the integers from 0 to `n - 1`.

You may perform  **only**  the following operations:

- Reverse the entire array.
- Rotate Left by One: Move the first element to the end of the array, and rest elements to left by one position.

Return an integer denoting the  **minimum**  number of operations required to sort the array in  **increasing**  order. If it is  **not possible**  to sort the array using only the given operations, return -1.

 

 **Example 1:** 

 **Input:**  nums = [0,2,1]

 **Output:**  2

 **Explanation:** 

- Rotate Left by one: [2, 1, 0]
- Reverse the array: [0, 1, 2]

The array becomes sorted in 2 operations, which is minimal

 **Example 2:** 

 **Input:**  nums = [1,0,2]

 **Output:**  2

 **Explanation:** 

- Reverse the array: [2, 0, 1]
- Rotate Left by one: [0, 1, 2]

The array becomes sorted in 2 operations, which is minimal.

 **Example 3:** 

 **Input:**  nums = [2,0,1,3]

 **Output:**  -1

 **Explanation:** 

It is impossible to reach `[2, 0, 1, 3]`. Thus, the answer is -1.

 

 **Constraints:** 

- 1 <= n == nums.length <= 105
- 0 <= nums[i] <= n - 1
- nums is a permutation of integers from 0 to n - 1.

## Solution

**Language:** C++  
**Runtime:** 42 ms (beats 7.87%)  
**Memory:** 165.6 MB (beats 6.30%)  
**Submitted:** 2026-10-22T15:06:40.612Z  

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> starts;
        bool inc = true, dec = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(i + 1) % n] != (nums[i] + 1) % n) inc = false;
            if (nums[(i + 1) % n] != (nums[i] - 1 + n) % n) dec = false;
        }
        if (inc) starts.emplace_back(0, nums[0]);
        if (dec) starts.emplace_back(1, (n - 1 - nums[0] + n) % n);
        if (starts.empty()) return -1;

        vector<vector<int>> dist(2, vector<int>(n, -1));
        queue<pair<int,int>> q;
        for (auto [t, s] : starts) {
            dist[t][s] = 0;
            q.emplace(t, s);
        }
        while (!q.empty()) {
            auto [t, s] = q.front(); q.pop();
            if (t == 0 && s == 0) return dist[t][s];
            int d = dist[t][s];
            int nt = t, ns = (s + 1) % n;
            if (dist[nt][ns] == -1) {
                dist[nt][ns] = d + 1;
                q.emplace(nt, ns);
            }
            nt = 1 - t;
            ns = (n - s) % n;
            if (dist[nt][ns] == -1) {
                dist[nt][ns] = d + 1;
                q.emplace(nt, ns);
            }
        }
        return -1;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-operations-to-sort-a-permutation/)