# balancing-pan5038

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-10T10:47:23.395Z  

```cpp
class Solution {
  public:
    bool balancePan(int a, int b) {
        // code here
        if (a <= 0 or b < 0) return 0;
                if (a == 1) return 1;

                while (b) {
                    int r = b % a;
                    if (r == 0) b /= a;
                    else if (r == 1) b = (b - 1) / a;
                    else if (r == a - 1) b = (b + 1) / a;
                    else return 0;
                }

                return 1;
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/balancing-pan5038/1)