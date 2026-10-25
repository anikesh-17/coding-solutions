# EXQUIZ - Rating 931

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Exun Quiz

The prelims of the Exun quiz have $N$ questions. A correct answer earns $4$ points, a wrong answer costs $1$ point, and a skipped question gives $0$ points.

After the prelims, a team walks up to the quizmaster with a final score of $S$. The quizmaster is curious: what is the smallest number of questions the team could have attempted (answered correctly or wrongly) to finish with exactly $S$ points? If no way of answering the $N$ questions gives exactly $S$ points, the scoresheet must contain an error.

### Input Format
- The first line of input contains a single integer $T$, denoting the number of test cases.
- Each test case consists of a single line containing two space-separated integers $N$ and $S$.
### Output Format

For each test case, output on a new line the minimum number of attempted questions, or $-1$ if a score of exactly $S$ is impossible.

### Constraints
- $1 \leq T \leq 10000$
- $1 \leq N \leq 50$
- $0 \leq S \lt 200$
### Sample 1:
Input
Output

```
6
10 7
10 9
10 40
7 0
1 3
1 5

```

```
3
6
10
0
-1
-1

```

### Explanation:

Test case $1$: $2$ correct answers and $1$ wrong answer give $8 - 1 = 7$ points with $3$ attempts.

Test case $4$: Since the final score is $0$, all questions can be skipped.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-25T12:17:46.609Z  

```c_cpp
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector < int > ;
using vll = vector < ll > ;
using pii = pair < int, int > ;

#define pb push_back
#define all(x)(x).begin(), (x).end()
#define sz(x)(int)(x).size()
#define endl '\n'

void fahhh() {
    int n, s;
    cin >> n >> s;
    if (s % 4 == 0 && s / 4 <= n)
        cout << s / 4 << endl;
    else if (s % 4 == 1 && (s + 15) / 4 <= n)
        cout << (s + 15) / 4 << endl;
    else if (s % 4 == 2 && (s + 10) / 4 <= n)
        cout << (s + 10) / 4 << endl;
    else if (s % 4 == 3 && (s + 5) / 4 <= n)
        cout << (s + 5) / 4 << endl;
    else
        cout << -1 << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        fahhh();
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/EXQUIZ)