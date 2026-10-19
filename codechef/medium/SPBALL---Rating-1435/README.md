# SPBALL - Rating 1435

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Spliting Balls

There are $N$ balls in a bag. Initially, the $i^{th}$ ball has a number $A_i$ on it.

In one second, a ball with number $k$ $(k>1)$, dissociates into $k$ balls, where each of the $k$ balls has number $(k-1)$ written on it.
If $k = 1$, there is no change on the state of the ball.

Find the number of balls in the bag after $10^{100}$ seconds. Since the final number of balls can be huge, output the answer modulo $10^9+7$.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains an integer $N$, denoting the number of balls in the bag. The next line contains $N$ space-separated integers $A_1, A_2, \ldots, A_N$, denoting the initial number written on the balls.
### Output Format

For each test case, output on a new line, the number of balls in the bag after $10^{100}$ seconds. Since the final number of balls can be huge, output the answer modulo $10^9+7$.

### Constraints
- $1 \leq T \leq 10^4$
- $1 \leq N \leq 2\cdot 10^5$
- $1 \leq A_i \leq 10^6$
- The sum of $N$ over all test cases won't exceed $2\cdot 10^5$.
### Sample 1:
Input
Output

```
3
1
2
2
1 2
3
3 1 3

```

```
2
3
13

```

### Explanation:

 **Test case $1$:**  Initially, the balls in the bag are $\{2\}$.

- After $1$ second: The ball with number $2$ dissociates into two balls with number $1$. Thus, the bag looks like $\{1, 1\}$.

No more dissociation is possible after this. Thus, the final number of balls is $2$.

 **Test case $2$:**  Initially, the balls in the bag are $\{1, 2\}$.

- After $1$ second: The ball with number $2$ dissociates into two balls with number $1$. Thus, the final bag looks like $\{1, 1, 1\}$.

No more dissociation is possible after this. Thus, the final number of balls is $3$.

 **Test case $3$:**  Initially, the balls in the bag are $\{3, 1, 3\}$.

- After $1$ second: The balls with number $3$ dissociates into three balls with number $2$. Thus, the bag looks like $\{2, 2, 2, 1, 2, 2, 2\}$.
- After $2$ seconds: The balls with number $2$ dissociates into two balls with number $1$. Thus, the bag looks like $\{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1\}$.

No more dissociation is possible after this. Thus, the final number of balls is $13$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-19T15:03:17.216Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/* auth : sayan_shaw */
ll fac[1000003];
void init(ll fac[]) {
    fac[1] = 1;
    for(ll i = 2; i < 1000003; i++) {
        fac[i] = (i * fac[i - 1]) % 1000000007;
    }
}
int main(void) {
    init(fac);
	ll  test_case;
	cin >> test_case;
	while(test_case--) {
        ll n, a, ans = 0;
        cin >> n;
        for(ll i = 0; i < n; i++) {
            cin >> a;
            ans = (ans + fac[a]) % 1000000007;
        }
        cout << ans << endl;
	}
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/SPBALL)