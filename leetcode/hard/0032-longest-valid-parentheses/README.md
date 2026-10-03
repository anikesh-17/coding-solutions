# Longest Valid Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string containing just the characters `'('` and `')'`, return  *the length of the longest valid (well-formed) parentheses **substring*.

 

 **Example 1:** 

```
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

```

 **Example 2:** 

```
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

```

 **Example 3:** 

```
Input: s = ""
Output: 0

```

 

 **Constraints:** 

- 0 <= s.length <= 3 * 104
- s[i] is '(', or ')'.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 11.6 MB (beats 70.93%)  
**Submitted:** 2026-10-03T11:51:52.334Z  

```cpp
class Solution {
public:
    int longestValidParentheses(auto& s) {
        int res = 0;
        vector<int> stack = {-1};
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                stack.push_back(i);
            else {
                stack.pop_back();
                
                if (stack.empty())
                    stack.push_back(i);
                else
                    res = max(res, i - stack.back());
            }
        }
        
        return res;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-valid-parentheses/)