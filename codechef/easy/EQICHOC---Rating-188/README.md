# EQICHOC - Rating 188

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Game Controller

Chef is playing a game where his character starts at position $0$.

Pressing the right button moves the character $1$ step to the right. Pressing the left button moves it $1$ step to the left.

Chef presses the right button $R$ times and the left button $L$ times. Find how many steps the character is from its starting position after all the presses.

### Input Format

The only line contains two space-separated integers $R$ and $L$.

### Output Format

Print the number of steps between the character's final position and its starting position.

### Constraints
- $0 \le R, L \le 100$
### Sample 1:
Input
Output

```
3 8
```

```
5
```

### Explanation:

The character finishes $5$ steps to the left of its starting position, so the distance is $5$.

### Sample 2:
Input
Output

```
4 4
```

```
0
```

### Explanation:

The character returns to its starting position.

### Sample 3:
Input
Output

```
10 2
```

```
8
```

### Explanation:

The character finishes $8$ steps to the right of its starting position, so the distance is $8$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-26T15:51:46.326Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int a,b;
	cin>>a>>b;
	cout << abs(a-b) << endl;

}

```

---

[View on CodeChef](https://www.codechef.com/problems/EQICHOC)