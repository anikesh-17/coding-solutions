# lexicographically-smallest-string--151951

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-02T12:42:21.169Z  

```cpp
class Solution {
  public:
    string lexiString(string &s) {
        // code here
        string doubled = s + s;
                int n = doubled.size();
                vector<int> f(n, -1);
                int k = 0;
                for (int j = 1; j < n; j++) {
                    char sj = doubled[j];
                    int i = f[j - k - 1];
                    while (i != -1 && sj != doubled[k + i + 1]) {
                        if (sj < doubled[k + i + 1]) {
                            k = j - i - 1;
                        }
                        i = f[i];
                    }
                    if (sj != doubled[k + i + 1]) {
                        if (sj < doubled[k]) {
                            k = j;
                        }
                        f[j - k] = -1;
                    } else {
                        f[j - k] = i + 1;
                    }
                }
                return doubled.substr(k, s.size());
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/lexicographically-smallest-string--151951/1)