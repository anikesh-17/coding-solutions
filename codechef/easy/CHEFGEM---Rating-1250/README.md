# CHEFGEM - Rating 1250

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Chef and the Gemstones

Chef is on an adventure in a deep cave, collecting unique gemstones of various values one by one. As he puts each gemstone into his bag, he wants to keep track of the $K$-th most valuable gemstone in his collection so far.

If he has collected fewer than $K$ gemstones, the $K$-th most valuable gemstone does not exist yet, so he records  **-1**.

All gemstone values will be distinct. Help Chef automate this task!

### Input Format
- The first line of input contains an integer $T$ denoting the number of test cases.
- Each test case contains two lines: The first line contains two space-separated integers $K$ and $N$ — the target rank and the number of gemstones Chef collects, respectively. The second line contains $N$ space-separated integers representing the values of the gemstones in the order Chef collects them.
### Output Format
- For each testcase, print a single line containing $N$ space-separated integers denoting the $K$-th most valuable gemstone or -1.
### Constraints
- $1 \le T \le 10$
- $1 \le N, K \le 10^4$
- $1 \le N_i \le 10^9$
### Sample 1:
Input
Output

```
2
4 6
1 2 3 4 5 6
1 4
4 3 6 5
```

```
-1 -1 -1 1 2 3
4 4 6 6
```

### Explanation:
- Test Case 1 ($K = 4$): Until the 4th gemstone is collected, the 4th highest value does not exist (outputs -1). Once $\{1, 2, 3, 4\}$ are collected, the 4th highest is $1$. As $5$ and $6$ are added, the 4th highest shifts to $2$ and then $3$.
- Test Case 2 ($K = 1$): We track the maximum value in the collection at each step. As elements $\{4, 3, 6, 5\}$ are added, the maximums are $4$, $4$, $6$, and $6$ respectively.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-05T12:59:04.660Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k, n;
    cin >> k >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        int ni;
        cin >> ni;
        if(i < k) {
            pq.push(ni);
        }
        else {
            if(pq.top() < ni) {
                pq.pop();
                pq.push(ni);
            }
        }
        if(i < k - 1) {
            cout << -1 << " ";
        }
        else {
            cout << pq.top() << " ";
        }
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
	return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/CHEFGEM)