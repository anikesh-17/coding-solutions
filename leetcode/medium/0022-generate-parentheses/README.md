# Generate Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given `n` pairs of parentheses, write a function to  *generate all combinations of well-formed parentheses*.

 

 **Example 1:** 

```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

```

 **Example 2:** 

```
Input: n = 1
Output: ["()"]

```

 

 **Constraints:** 

- 1 <= n <= 8

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 14.2 MB (beats 65.08%)  
**Submitted:** 2026-10-02T12:43:38.493Z  

```cpp
class Solution { 
public: 
    vector<string> generateParenthesis(int n) { 
        vector<string> ans;
        string cur;
        function<void(int,int)> dfs = [&](int open, int close) {
            if (open == 0 && close == 0) {
                ans.push_back(cur);
                return;
            }
            if (open > 0) {
                cur.push_back('(');
                dfs(open - 1, close);
                cur.pop_back();
            }
            if (close > open) {
                cur.push_back(')');
                dfs(open, close - 1);
                cur.pop_back();
            }
        };
        dfs(n, n);
        return ans;
    } 
};
```

---

[View on LeetCode](https://leetcode.com/problems/generate-parentheses/)