# CODEXP - Rating 460

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### CodeChef XP

Chef is active on CodeChef and earns XP by contributing to the platform.

- Solving a problem earns him $A$ XP.
- Writing an editorial earns him $B$ XP.

Today, Chef solved  **$P$**  problems and wrote  **$E$**  editorials. Find the  **total**  XP earned by Chef today.

### Input Format

A single line containing four space-separated integers:
$A \quad B \quad P \quad E$

### Output Format

Print a single integer — the total XP earned by Chef.

### Constraints
- $1 \le A, B \le 100$
- $0 \le P, E \le 100$
### Sample 1:
Input
Output

```
10 50 3 2
```

```
130
```

### Explanation:

Chef earns:
$10 \times 3 = 30$ XP from solving problems
$50 \times 2 = 100$ XP from writing editorials.
Total XP earned is $30 + 100 = 130$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-04T14:43:39.676Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, P, E;
    cin >> A >> B >> P >> E;
    cout << A * P + B * E << "\n";
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/CODEXP)