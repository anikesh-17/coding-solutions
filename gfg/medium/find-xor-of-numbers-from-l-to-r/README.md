# find-xor-of-numbers-from-l-to-r

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-18T15:57:34.048Z  

```cpp

class Solution {
public:
    int findXOR(int l, int r) {

        auto xorUpto = [](int n) {
            if (n % 4 == 0) return n;
            if (n % 4 == 1) return 1;
            if (n % 4 == 2) return n + 1;
            return 0;
        };

        return xorUpto(r) ^ xorUpto(l - 1);
    }
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1)