# Q2. Minimum Cost to Make All Array Elements Equal

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` of length `n`.

You may perform  **any**  of the following operations  **any**  number of times, in  **any**  order.

- Prefix operation: Choose an index i such that 0 < i < n - 1, and set all elements from index 0 to i - 1 to nums[i]. The cost of this operation is i * nums[i].
- Suffix operation: Choose an index i such that 0 < i < n - 1, and set all elements from index i + 1 to n - 1 to nums[i]. The cost of this operation is (n - i - 1) * nums[i].

The cost is based on the  **current**  value of `nums[i]` and includes every element in the chosen prefix or suffix, even if it already equals `nums[i]`.

Return the  **minimum total cost**  required to make  **all**  elements of `nums` equal.

 

Original
C++
 **Example 1:** 

 **Input:**  nums = [1,2,3]

 **Output:**  4

 **Explanation:** 

One sequence of operations that achieves the minimum cost is as follows:

nums	Operation	i	Modified nums	Cost
[1, 2, 3]	Suffix	1	[1, 2, 2]	(3 - 1 - 1) * 2 = 2
[1, 2, 2]	Prefix	1	[2, 2, 2]	1 * 2 = 2

Hence, the total cost is `2 + 2 = 4`.

 **Example 2:** 

 **Input:**  nums = [3,3,3,6,3,3]

 **Output:**  9

 **Explanation:** 

One sequence of operations that achieves the minimum cost is as follows:

nums	Operation	i	Modified nums	Cost
[3, 3, 3, 6, 3, 3]	Suffix	2	[3, 3, 3, 3, 3, 3]	(6 - 2 - 1) * 3 = 9

Hence, the total cost is 9.

 **Example 3:** 

 **Input:**  nums = [3,4,4,5,4,4,3]

 **Output:**  20

 **Explanation:** 

One sequence of operations that achieves the minimum cost is as follows:

nums	Operation	i	Modified nums	Cost
[3, 4, 4, 5, 4, 4, 3]	Prefix	4	[4, 4, 4, 4, 4, 4, 3]	4 * 4 = 16
[4, 4, 4, 4, 4, 4, 3]	Suffix	5	[4, 4, 4, 4, 4, 4, 4]	(7 - 5 - 1) * 4 = 4

Hence, the total cost is `16 + 4 = 20`.

 

 **Constraints:** 

- 3 <= n == nums.length <= 105
- 1 <= nums[i] <= 109

## Solution

**Language:** C++  
**Runtime:** 7 ms (beats 48.60%)  
**Memory:** 207.9 MB (beats 96.01%)  
**Submitted:** 2026-11-27T19:18:09.941Z  

```cpp
class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MAX;
        for(int i =0; i<n;){
            int j = i;
            while(j+1 < n && nums[j] == nums[j+1]) j++;
            if(i <= n-2 && j>=1){
                long long cost = 1LL * nums[i] * i + 1LL*(n-j-1)*nums[i];
                ans = min(ans, cost);
            }
            i = j+1;
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/minimum-cost-to-make-all-array-elements-equal/)