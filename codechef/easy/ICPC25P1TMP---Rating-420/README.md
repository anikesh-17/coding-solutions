# ICPC25P1TMP - Rating 420

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### A - Lecture Capacity

A college club is going to host an ICPC-style contest for its college students.
Each team participating in the contest should have  **exactly**  three participants.

There are $n$ teams participating in the contest. How many participants are there in total?

- Time Limit - 1 second
- Memory Limit - 1.5GB
### Input Format
- The only line of input contains a single integer $n$, denoting the number of teams that will be participating.
### Output Format
- Output a single integer: the total number of participants.
### Constraints
- $1 \le n \le 1000$
### Sample 1:
Input
Output

```
1
```

```
3
```

### Explanation:

There is one team. Each team must have $3$ participants, so there are $3$ participants in total.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-01T05:37:23.568Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin>>n;
	cout << n*3 << endl;

}

```

---

[View on CodeChef](https://www.codechef.com/problems/ICPC25P1TMP)