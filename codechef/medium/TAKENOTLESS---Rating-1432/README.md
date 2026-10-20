# TAKENOTLESS - Rating 1432

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Take Not Less

Zenyk and Marichka are playing a game taking turns alternatively. They have $N$ piles of stones. In the $i^{th}$ pile, there are $A_i$ stones initially.

Marichka goes first, and removes any  **non-zero**  number of stones from any pile.
After that, in one move, a player can take any number of stones from any pile,  **but not less**  than the number of stones taken by the opponent in the previous move.

The player who cannot make a move loses. If both players play optimally, find the winner of the game.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- The first line of each tets case contains single integer $N$ — the number of piles.
- The second line of each test case contains $N$ space-separated integers $A_1, A_2, \ldots, A_N$ — the numbers of stones in piles initially.
### Output Format

For each test case, output a new line containing:

- Marichka if Marichka wins.
- Zenyk if Zenyk wins.

Note that you may print each character in lowercase or uppercase. For example, the strings `Zenyk`, `ZENYK`, `zenyk`, and `zEnYK` are considered identical.

### Constraints
- $1 \le T \le 10^5$
- $1 \le N \le 10^5$
- $1 \le A_i \le 10^9$
- Sum of $N$ over all test cases doesn't exceed $2 \cdot 10^5$
### Sample 1:
Input
Output

```
3
3
1 2 3
2
1 1
1
10

```

```
Marichka
Zenyk
Marichka

```

### Explanation:

For the first testcase, Marichka can take $3$ stones from the last pile in the first move, then Zenyk won't be able to make a move, as each pile will contain less than $3$ stones.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-20T13:35:42.096Z  

```c_cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, i, db;
    cin >> t;
    while (t--) {
        db = 1;
        cin >> n;
        int a[n];
        map < int, int > mp;
        for (i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        for (i = n - 1; i >= 0; i--) {
            if (mp[a[i]] % 2) {
                cout << "Marichka";
                db = 0;
                break;
            }
        }
        if (db) {
            cout << "Zenyk";
        }
        /*	    cout<<max<<" "<<c;
        	    if(n==1){
        	        cout<<"Marichka";
        	    }
        	    else{
        	        if(c%2==1){
        	            cout<<"Marichka";
        	        }
        	        else{
        	            cout<<"Zenyk";
        	        }
        	    } */
        cout << "\n";
    }
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/TAKENOTLESS)