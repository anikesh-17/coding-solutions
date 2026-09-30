# LMP3 - Rating 1409

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Odd Operations

You are given an integer $N$. You can perform the following two types of operations on $N$:

- Digit Subtraction: Choose any digit present in the current decimal representation of $N$ and subtract it from $N$.
- Digit Reordering: Rearrange (permute) the digits of $N$ to form a new integer (Leading zeros are not allowed). For example, $1067$ can be rearranged to $7106$ but not to $10670$. Also, $90$ cannot be rearranged to $9$.

Determine the  **minimum number of operations**  required to make $N$ an  **odd**  number.

If it is  **impossible**  to make $N$ odd using the given operations, print  **$-1$**.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each of the next $T$ lines contains a single integer $N$.
### Output Format

For each test case, output a single integer — the minimum number of operations required to make $N$ odd.
If it is not possible, output $-1$.

### Constraints
- $1 \leq T \leq 10^5$
- $1 \leq N \lt 10^9$
### Sample 1:
Input
Output

```
5
246
10
8
343
42

```

```
3
1
-1
0
2

```

### Explanation:
- For the first test case, $N = 246$. One optimal sequence of operations is: Subtract digit $6$: $246 - 6 = 240$ Subtract digit $2$: $240 - 2 = 238$ Subtract digit $3$: $238 - 3 = 235$, which is odd Hence, the minimum number of operations required is $3$.
- For the second test case, $N = 10$. Subtract digit $1$ from $10$ to get $9$, which is odd. Hence, the answer is $1$.
- For the third test case, $N = 8$. It is impossible to make $N$ odd and the answer is $-1$.
- For the fourth test case, $N = 343$. The number is already odd, so no operations are required. Hence, the answer is $0$.
- For the fifth test case, $N = 42$. One optimal sequence is: Subtract digit $4$: $42 - 4 = 38$ Reorder $38$ to $83$ Hence, the answer is $2$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-30T11:57:20.233Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

bool has_odd(long long n) {
    string s = to_string(n);
    for (char c : s) {
        int d = c - '0';
        if (d % 2 == 1) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        if (n % 2 == 1) {
            cout << 0 << '\n';
        }
        else if (has_odd(n)) {
            cout << 1 << '\n';
        }
        else {
            int ans = (n >= 10 ? 3 : -1);
            string s = to_string(n);
            for (char c : s) {
                int d = c - '0';
                if (has_odd(n - d)) {
                    ans = 2;
                    break;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/LMP3)