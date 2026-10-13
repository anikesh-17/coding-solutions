# Maximum Alternating Sum of Squares

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums`. You may  **rearrange the elements**  in any order.

The  **alternating score**  of an array `arr` is defined as:

- score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 +...

Return an integer denoting the  **maximum possible alternating score**  of `nums` after rearranging its elements.

 

 **Example 1:** 

 **Input:**  nums = [1,2,3]

 **Output:**  12

 **Explanation:** 

A possible rearrangement for `nums` is `[2,1,3]`, which gives the maximum alternating score among all possible rearrangements.

The alternating score is calculated as:

`score = 22 - 12 + 32 = 4 - 1 + 9 = 12`

 **Example 2:** 

 **Input:**  nums = [1,-1,2,-2,3,-3]

 **Output:**  16

 **Explanation:** 

A possible rearrangement for `nums` is `[-3,-1,-2,1,3,2]`, which gives the maximum alternating score among all possible rearrangements.

The alternating score is calculated as:

`score = (-3)2 - (-1)2 + (-2)2 - (1)2 + (3)2 - (2)2 = 9 - 1 + 4 - 1 + 9 - 4 = 16`

 

 **Constraints:** 

- 1 <= nums.length <= 105
- -4  *104 <= nums[i] <= 4*  104

## Solution

**Language:** C++  
**Runtime:** 67 ms (beats 35.91%)  
**Memory:** 191.6 MB (beats 21.05%)  
**Submitted:** 2026-10-13T10:52:34.003Z  

```cpp
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // Step 1: square every number (long long, so it cannot overflow)
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            a[i] = 1LL * nums[i] * nums[i];

        // Step 2: sort — smallest on the left, biggest on the right
        sort(a.begin(), a.end());

        long long ans = 0;
        int k = n / 2;   // number of minus places

        // Step 3: subtract the k smallest squares
        for (int i = 0; i < k; i++)
            ans -= a[i];

        // Step 4: add all the bigger squares
        for (int i = k; i < n; i++)
            ans += a[i];

        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/maximum-alternating-sum-of-squares/)