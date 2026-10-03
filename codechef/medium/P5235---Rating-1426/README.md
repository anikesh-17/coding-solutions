# P5235 - Rating 1426

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### MEX Spectrum

You are given an array $A$ of length $N$ consisting of non-negative integers, where $0 \leq A_i \leq N$ for every $i$.

In one  **operation**, you may:

- Choose any subarray $A[l \ldots r]$ (a contiguous segment with $1 \leq l \leq r \leq N$).
- Compute $m = \mathrm{MEX}(A_l, A_{l+1}, \ldots, A_r)$.
- Choose any index $i$ with $l \leq i \leq r$, and set $A_i := m$.

For  **every**  integer $K$ from $0$ to $N$, determine the  **minimum number of operations**  required to make the MEX of the entire array $A$ equal to exactly $K$. Each value of $K$ is considered independently — that is, for each $K$, you start fresh from the original array.

 **Note:**  The  **MEX**  of a collection of non-negative integers is the smallest non-negative integer that does  **not**  appear in the collection. For example, $\mathrm{MEX}(\{0, 1, 3\}) = 2$, $\mathrm{MEX}(\{1, 2\}) = 0$, and $\mathrm{MEX}(\{0, 1, 2\}) = 3$.

### Input Format
- The first line of input contains a single integer $T$ — the number of test cases.
- The first line of each test case contains a single integer $N$ — the length of the array.
- The second line of each test case contains $N$ space-separated integers $A_1, A_2, \ldots, A_N$.
### Output Format

For each test case, print $N + 1$ space-separated integers on a single line: the $k$-th integer (for $k = 0, 1, \ldots, N$) must equal the minimum number of operations required to make $\mathrm{MEX}(A) = k$.

### Constraints
- $1 \leq T \leq 10^5$
- $1 \leq N \leq 2 \cdot 10^5$
- $0 \leq A_i \leq N$
- The sum of $N$ over all test cases does not exceed $2 \cdot 10^5$.
### Sample 1:
Input
Output

```
3
3
0 1 2
4
2 2 2 2
3
1 1 1
```

```
1 1 1 0
0 1 4 2 3
0 3 1 2
```

### Explanation:

 **Test case 1:**  $A = [0, 1, 2]$. The array already has MEX $= 3$, so no operations are needed for $K = 3$. For $K = 2$, one valid operation is: choose the subarray $A[3 \ldots 3] = [2]$ whose MEX is $0$, and set $A_3 := 0$. The array becomes $[0, 1, 0]$ with MEX $= 2$.

 **Test case 2:**  $A = [2, 2, 2, 2]$. For $K = 2$, one valid sequence of $4$ operations is:

- Choose $A[1 \ldots 1] = [2]$ with MEX $= 0$; set $A_1 := 0$, giving $[0, 2, 2, 2]$.
- Choose $A[1 \ldots 2] = [0, 2]$ with MEX $= 1$; set $A_2 := 1$, giving $[0, 1, 2, 2]$.
- Choose $A[3 \ldots 3] = [2]$ with MEX $= 0$; set $A_3 := 0$, giving $[0, 1, 0, 2]$.
- Choose $A[4 \ldots 4] = [2]$ with MEX $= 0$; set $A_4 := 0$, giving $[0, 1, 0, 0]$ with MEX $= 2$.

 **Test case 3:**  $A = [1, 1, 1]$. For $K = 2$, a single operation suffices: choose $A[1 \ldots 1] = [1]$ whose MEX is $0$, and set $A_1 := 0$. The array becomes $[0, 1, 1]$ with MEX $= 2$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-03T11:52:40.821Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        vector<int> freq(N + 1, 0);

        for (int i = 0; i < N; i++) {
            cin >> A[i];
            if (A[i] <= N) freq[A[i]]++;
        }

        vector<int> ans(N + 1);

        int missing = 0;

        for (int k = 0; k <= N; k++) {
            if (k > 0 && freq[k - 1] == 0) {
                missing++;
            }

            if (k == 0) {
                if (freq[0] == 0) ans[k] = 0;
                else ans[k] = freq[0];
            } else {
                if (missing == 0) {
                    ans[k] = freq[k];
                } else {
                    ans[k] = max(missing, freq[k]);
                }
            }
        }

        for (int k = 0; k <= N; k++) {
            cout << ans[k] << " ";
        }
        cout << '\n';
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/P5235)