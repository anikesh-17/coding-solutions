# GIT01 - Rating 1451

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Chef And his Cake

Chef’s girlfriend's birthday is near, so he wants to surprise her by making a special cake for her. Chef knows that his girlfriend likes cherries on the cake, so he puts cherries on the top of the cake, but he was not satisfied. Therefore, he decided to replace some of the cherries to make a beautiful pattern. However, Chef has a lot of other work to do so he decided to ask for your help.

The cherries are of two colors  **red**  and  **green**. Now Chef wants the cherries to be placed in such a way that each cherry of one color must be adjacent to only cherries of the other color, two cherries are adjacent if they share a side. Now Chef has asked for your help in making that pattern on the cake.

You can replace any cherry of given color with the other color. But there is a cost for each replacement: if you replace a red cherry with a green one, the cost is  **5**  units and if you replace a green cherry with a red one, the cost is  **3**  units.

Help your friend Chef by making the cake special with minimum cost.

### Input

- The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
- The first line of each test case contains two space-separated integers N and M, where N × M are the dimensions of the cake.
- Each of the next N lines contains a string of length M.

### Output

For each test case, output the minimum cost required to make the cake special.

### Constraints
- 1 ≤ T ≤ 100
- 1 ≤ N, M ≤ 100
- each string consists only of letters 'R' and 'G' denoting red and green cherries respectively
### Sample 1:
Input
Output

```
2
4 5
RGRGR
GRGRG
RGRGR
GRGRG
2 3
RRG
GGR
```

```
0
8
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-24T15:58:18.845Z  

```c_cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    // your code goes here

    long int t, n, m, i, j, ered, ored, egreen, ogreen;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        char a[m][n];
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        ered = 0;
        ored = 0;
        egreen = 0;
        ogreen = 0;
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if ((i + j) % 2 == 0 && a[i][j] == 'R')
                    ered++;
                else if ((i + j) % 2 != 0 && a[i][j] == 'R')
                    ored++;
                else if ((i + j) % 2 == 0 && a[i][j] == 'G')
                    egreen++;
                else if ((i + j) % 2 != 0 && a[i][j] == 'G')
                    ogreen++;
            }
        }
        long int ans1 = 0, ans2 = 0;
        ans1 = ered * 5 + ogreen * 3;
        ans2 = ored * 5 + egreen * 3;
        cout << min(ans1, ans2) << endl;

    }
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/GIT01)