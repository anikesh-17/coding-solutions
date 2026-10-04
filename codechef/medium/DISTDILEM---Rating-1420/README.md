# DISTDILEM - Rating 1420

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Distinct Dilemma

You are given an array $A$ of $N$ integers. You can do the following two types of operations any (possibly zero) number of times:

- Pick two indices $i$ and $j$ $(1 \leq i,j \leq |A|, i \neq j)$. Change $A_j := A_j + A_i$ and remove the $i^{th}$ element from the array.
- Pick an index $i$ $(1 \leq i \leq |A|)$. Split $A_i$ into two positive integers $X$ and $Y$ such that $X+Y=A_i$. Remove the $i^{th}$ element from the array and append elements $X$ and $Y$ to the array.

Find the  **maximum**  number of  **distinct**  elements present in the array after performing any number of operations of the above two types.

### Input Format
- The first line contains an integer $T$ denoting the number of test cases. The $T$ test cases then follow.
- The first line of each test case contains an integer $N$ - the size of the array.
- The second line of each test case contains $N$ space-separated integers $A_1, A_2, \dots, A_N$.
### Output Format

For each test case, output the maximum number of  **distinct**  elements present in the array after performing any number of operations of the above two types.

### Constraints
- $1 \le T \le 100$
- $2 \le N \le 1000$
- $1 \le A_i \le 10^5$
### Sample 1:
Input
Output

```
2
3
1 2 4
4
1 1 3 4
```

```
3
3
```

### Explanation:
- Test case $1$: The maximum number of distinct elements that can be achieved by performing some finite number of operations on the given array is $3$. Some examples of the final array are: $[1, 2, 4]$ : Perform no operation on the given array. $[1, 2, 1, 3]$ : Perform operation $2$. Choose $i = 3$. Here, $A_3 = 4$. Break it as $X = 1$ and $Y = 3$. On removing $A_3$ and appending $X$ and $Y$, we get $[1, 2, 1, 3]$. This array has $3$ distinct elements.
- Test case $2$: The maximum number of distinct elements that can be achieved by performing some finite number of operations on the given array is $3$. Some examples of the final array are: $[1, 1, 3, 4]$ : Perform no operation on the given array. $[1, 1, 3, 2, 2]$ : Perform operation $2$. Choose $i = 4$. Here, $A_4 = 4$. Break it as $X = 2$ and $Y = 2$. On removing $A_4$ and appending $X$ and $Y$, we get $[1, 1, 3, 2, 2]$. This array has $3$ distinct elements. $[2, 3, 4]$ : Perform operation $1$. Choose $i = 1$ and $j=2$. On changing $A_2 := A_1+A_2 = 1+1=2$ and removing $A_1$, we get $[2, 3, 4]$. This array has $3$ distinct elements.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-04T06:41:01.289Z  

```c_cpp
#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long sum = 0LL,cur_sum = 0LL;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    int distinct = 1;
    while(true){
        cur_sum += distinct;
        if(cur_sum > sum) break;
        distinct++;
    }
    cout << (distinct-1) << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
	return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/DISTDILEM)