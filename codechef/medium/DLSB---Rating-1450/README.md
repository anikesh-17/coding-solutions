# DLSB - Rating 1450

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Make Bob Win

Alice and Bob are playing a game. They have with them a binary string $S$.

Alice and Bob alternate making moves, with Alice going first.
On their turn, a player does the following:

- Choose a non-empty contiguous substring of $S$ all of whose characters are the same, delete it from $S$, and concatenate the remaining parts. More formally, choose integers $L$ and $R$ such that $1 \leq L \leq R \leq |S|$ and $S_L = S_{L+1} = \ldots = S_R$, and replace $S$ with the string $S_1S_2\ldots S_{L-1} S_{R+1}S_{R+2}\ldots S_{|S|}$. This reduces the length of $S$ by $R-L+1$.

Alice wins immediately when $S$ doesn't contain any occurrence of $1$, while Bob wins immediately when $S$ doesn't contain any occurrence of $0$. Both players will play to win.
Note that if the string initially doesn't contain any occurrences of $0$, Bob wins before any moves are made.

Bob wants to win the game, so  *before the game starts*, he can flip some characters of $S$.
That is, Bob can choose an index $i$ ($1 \leq i \leq N$), and set $S_i$ to $0$ if it was originally $1$, and vice versa.

Find the  **minimum**  number of flips Bob needs to make to ensure he can win.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains one integer $N$ — the length of $S$. The second line contains the binary string $S$.
### Output Format

For each test case, output on a new line the minimum number of flips required in $S$ to make Bob win.

### Constraints
- $1 \leq T \leq 10^5$
- $1 \leq N \leq 2\cdot 10^5$
- $S$ is a binary string, i.e, contains only the characters $0$ and $1$.
- The sum of $N$ over all test cases won't exceed $2\cdot 10^5$.
### Sample 1:
Input
Output

```
3
1
0
3
111
6
011001

```

```
1
0
1
```

### Explanation:

 **Test case $1$:**  Bob changes the only character of $S$, resulting in $S = \texttt{1}$.
There are no $0$'s in this string, so Bob wins automatically.

 **Test case $2$:**  There are no $0$'s in the string, so Bob wins without having to change anything.

 **Test case $3$:**  Bob can flip the first character of the string, turning it into $\texttt{111001}$.
It can be shown that if the game is played on this string, Bob will win; whereas he would lose if the game is played on the initial string.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-28T15:33:32.984Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
typedef vector<int> vli;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    int prev = -1;

    if(n == 1){
        if(s[0] == '1') cout<<0<<endl;
        else cout<<1<<endl;
        return;
    }
    
    int cnsZeros = 0, cnsOnes = 0;
    for(int i=0; i<n; i++){
        if(prev == -1){
            if(s[i]-'0' == 0){
                prev = 0;
                cnsZeros++;
            }
            else{
                prev = 1;
                cnsOnes++;
            }
        }
        else{
            if(s[i] - '0' == 0){
                if(prev){ cnsZeros++; prev = 0; }
            }   
            else{
                if(!prev){ cnsOnes++; prev = 1; }
            }
        }
    }

    // cout<<"CntZeros "<<cnsZeros<<" cnsOnes "<<cnsOnes<<endl;
    if(cnsZeros > cnsOnes) cout<<2<<endl;
    else if(cnsZeros == cnsOnes) cout<<1<<endl;
    else cout<<0<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/DLSB)