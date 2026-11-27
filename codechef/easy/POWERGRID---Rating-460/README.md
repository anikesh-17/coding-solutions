# POWERGRID - Rating 460

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Power Grid

A new park has been decorated with lamps for the evening.
The lamps are arranged in $R$ rows and $C$ columns. Every lamp uses $W$ watts of power.
Find the total power used by all the lamps.

### Input Format
- single line containing three space-separated integers $R$, $C$, and $W$.
### Output Format
- output a single integer representing the total power consumed by all the lamps.
### Constraints
- $1 \le R, C \le 10^2$
- $1 \le W \le 10^3$
### Sample 1:
Input
Output

```
3 4 5
```

```
60
```

### Explanation:

The park has $3 \times 4 = 12$ lamps. Each lamp uses $5$ watts. The total power used is $12 \times 5 = 60$ watts.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-27T14:56:18.826Z  

```c_cpp
#include <iostream>
using namespace std;

int main() {
    int R, C, W;
    cin >> R >> C >> W;
    cout << R * C * W;
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/POWERGRID)