# DIFFGCD - Rating 1345

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Difference is GCD

You are given an integer $N$. Count the number of pairs $(X, Y)$ such that:

- $1 \le X < Y \le N$
- $gcd(X, Y) = |X - Y|$

where $gcd(A, B)$ denotes the greatest common divisor of both $A$ and $B$.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- The first and only line of each test case contains a single integer $N$.
### Output Format

For each test case, output the number of pairs $(X, Y)$ satisfying the conditions.

### Constraints
- $1 \le T \le 100$
- $2 \le N \le 10^9$
### Sample 1:
Input
Output

```
4
2
3
4
10

```

```
1
2
4
17
```

### Explanation:

 **Test Case 1:**  $(1, 2)$ is the only pair.

 **Test Case 2:**  $(1, 2)$ and $(2, 3)$ are valid pairs.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-23T07:09:23.749Z  

```c_cpp
#include <iostream>

using namespace std;

void solve() {
    long long N;
    cin >> N;
    
    long long ans = 0;
    for (long long g = 1; g * 2 <= N; ) {
        long long val = N / g;
        long long max_g = N / val;
        
        // Ensure max_g doesn't exceed N / 2
        max_g = min(max_g, N / 2);
        
        // Count of values of g in the current block
        long long count = max_g - g + 1;
        
        ans += count * (val - 1);
        
        g = max_g + 1;
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/DIFFGCD)