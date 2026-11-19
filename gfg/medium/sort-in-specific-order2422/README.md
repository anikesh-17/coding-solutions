# Sort in Specific Order

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array  **arr[]**  of non-negative integers. Your need to sort them so that

- The first part of the array contains odd numbers sorted in descending order.
- The rest of the portion contains even numbers sorted in ascending order.

 **Examples:** 

```
Input: arr[] = [1, 2, 3, 5, 4, 7, 10]
Output: [7, 5, 3, 1, 2, 4, 10]
Explanation: 7, 5, 3, 1 are odd numbers in descending order and 2, 4, 10 are even numbers in ascending order.
```

```
Input: arr[] = [0, 4, 5, 3, 7, 2, 1]
Output: [7, 5, 3, 1, 0, 2, 4]
Explanation: 7, 5, 3, 1 are odd numbers in descending order and 0, 2, 4 are even numbers in ascending order.
```

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-19T15:28:08.841Z  

```cpp
class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // code here
        vector<int> odd, even;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            if(arr[i] % 2 == 0){
                even.push_back(arr[i]);
            }
            else{
                odd.push_back(arr[i]);
            }
        }
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end());
        
        int idx = 0;
        for (int x : odd) {
            arr[idx++] = x;
        }
        for (int x : even) {
            arr[idx++] = x;
        }
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/sort-in-specific-order2422/1)