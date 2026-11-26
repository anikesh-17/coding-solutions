# Smallest Unique Subarray

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an integer array `nums`.

Find the  **minimum** length of a subarray that is  **not**   **identical**  to any other  **subarray**  in `nums`.

Return an integer denoting the  **minimum possible length**  of such a  **subarray**.

Two  **subarrays**  are considered identical if they have the same length and the same elements in corresponding positions.

 

Original
C++
 **Example 1:** 

 **Input:**  nums = [3,3,3]

 **Output:**  3

 **Explanation:** 

- Subarrays of length 1: [3] → appears 3 times
- Subarrays of length 2: [3, 3] → appears 2 times
- Subarrays of length 3: [3, 3, 3] → appears once

The subarray `[3, 3, 3]` is unique, so the smallest unique subarray length is 3.

 **Example 2:** 

 **Input:**  nums = [2,1,2,3,3]

 **Output:**  1

 **Explanation:** 

Subarrays of length 1:

- [2] → appears 2 times
- [1] → appears once
- [3] → appears 2 times
The subarray `[1]` is unique, so the smallest unique subarray length is 1.

 **Example 3:** 

 **Input:**  nums = [1,1,2,2,1]

 **Output:**  2

 **Explanation:** 

Subarrays of length 1:

- [1] → appears 3 times
- [2] → appears 2 times

Subarrays of length 2:

- [1, 1] → appears once
- [1, 2] → appears once
- [2, 2] → appears once
- [2, 1] → appears once
There is at least one subarray of length 2 that is unique, so the smallest unique subarray length is 2.

 

 **Constraints:** 

- 1 <= nums.length <= 105
- 1 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 1554 ms (beats 9.30%)  
**Memory:** 508.9 MB (beats 5.81%)  
**Submitted:** 2026-11-25T16:14:23.229Z  

```cpp
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> names{nums};  // names[k][i] is equal for equal windows of length 2^k starting at i
        for (int half = 1; 2 * half <= n; half *= 2) {  // blocks of 2, 4, 8, ... while they fit
            unordered_map<long long, int> ids;  // pair of halves -> number of the whole window
            vector<int> whole;
            for (auto [a, b] : views::zip(names.back(), names.back() | views::drop(half)))
                whole.push_back(ids.try_emplace((long long)a << 32 | b, ids.size()).first->second);
            names.push_back(std::move(whole));
        }

        auto found = [&](int length) {  // is some window of this length unique?
            int k = bit_width((unsigned)length) - 1;  // its first 2^k elements and its last 2^k cover it
            unordered_map<long long, int> count;
            for (auto [a, b] : views::zip(names[k], names[k] | views::drop(length - (1 << k))))
                count[(long long)a << 32 | b]++;
            return ranges::any_of(count, [](auto& entry) { return entry.second == 1; });
        };

        return *ranges::partition_point(views::iota(1, n), not_fn(found));
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/smallest-unique-subarray/)