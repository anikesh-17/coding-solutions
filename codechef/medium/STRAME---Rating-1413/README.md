# STRAME - Rating 1413

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### String Game

Zlatan and Ramos are playing a game on a  **binary**  string $S$ of length $N$.
Zlatan and Ramos make alternating moves with Zlatan going first.

In one move, a player will:

- Select an index $i$ $(1 \leq i < N)$ such that $S_i \neq S_{i+1}$ and delete both $S_i$ and $S_{i+1}$ from the string $S$. Note that $N$ gets reduced by $2$ when both characters are deleted. If a player cannot select any such index $i$, he loses the game.

Determine the winner of the game if both players play optimally.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of multiple lines of input. The first line of each test case contains an integer $N$ — the length of the binary string. The next line contains a binary string $S$ of length $N$.
### Output Format

For each test case, if Zlatan will win the game, output `Zlatan`. Otherwise, output `Ramos`.

You can output each letter of the string in uppercase or lowercase. For example, `Ramos`, `ramos`, `RAMOS`, and `rAmOS` are all considered same.

### Constraints
- $1 \leq T \leq 10^5$
- $1 \leq N \leq 10^5$.
- $S$ consists of $0$ and $1$ only.
- The sum of $N$ over all test cases won't exceed $3 \cdot 10^5$.
### Sample 1:
Input
Output

```
5
1
0
2
11
2
10
3
111
3
101

```

```
Ramos
Ramos
Zlatan
Ramos
Zlatan

```

### Explanation:

 **Test case $1$:**  Zlatan goes first and has no move to make. Thus, Ramos wins.

 **Test case $2$:**  Zlatan goes first and has no move to make. Thus, Ramos wins.

 **Test case $3$:**  Zlatan goes first and selects $i=1$ where $S_1\neq S_2$. Thus, he removes $S_1$ and $S_2$.
Since the string is empty now, Ramos has no move to make and Zlatan wins.

 **Test case $4$:**  Zlatan goes first and has no move to make. Thus, Ramos wins.

 **Test case $5$:**  Zlatan goes first and selects $i=1$ where $S_1\neq S_2$. Thus, he removes $S_1$ and $S_2$.
Since the string only has length $1$ now, Ramos has no move to make and Zlatan wins.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-01T11:08:19.871Z  

```c_cpp
#include <bits/stdc++.h>

using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, cnt = 0;
        string s;
        cin >> n >> s;
        stack < char > st;
        for (auto i: s) {
            if (!st.empty() && st.top() != i) {
                st.pop();
                cnt++;
            }
            else st.push(i);
        }
        if (cnt % 2 == 0) cout << "Ramos";
        else cout << "Zlatan";
        cout << endl;
    }
}
```

---

[View on CodeChef](https://www.codechef.com/problems/STRAME)