# the-pattern-matcher

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-17T15:52:21.465Z  

```cpp
class Solution {
  public:
    bool findPattern(string& s) {
        // code here
        int cnt=0;
               int n=s.size();
               int i=0;
               while(i<n)
               {
                   while(i<n && s[i]=='x')
                   {
                       i++;
                       cnt++;
                   }
                   while(i<n && s[i]=='y')
                   {
                       i++;
                       cnt--;
                   }
                   if(cnt<0 || cnt>0)
                   {
                       return false;
                   }
               }
               return cnt==0;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/the-pattern-matcher/1)