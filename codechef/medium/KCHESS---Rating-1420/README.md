# KCHESS - Rating 1420

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Knight Chess

Abhineet the Chess master of NIT Kurukshetra got bored of 8x8 chess board and invented the new variation of Chess, the one on an infinite chess board. There is only a white king and $N$ black knights. The white king has to avoid checkmate as long as it can.

A situation is given. Determine if white king is in checkmate or not. The white king is in checkmate if and only if it is in check and it is not able to move to any of its neighboring positions which is not in check.

###Input:

- The first line will contain $T$, number of test cases. Then the test cases follow.
- The first line of each test case contains a single integer $N$.
- The next N line contains 2 space-separated integers $Xi$ and $Yi$ denoting the position of knights.
- The next line contains 2 space-separated integers $A$ and $B$ denoting the position of king

###Output: Print a single line corresponding to each test case — “YES” (without quotes) – if the king is in checkmate and “NO” (without quotes) – if the king is not in checkmate.

###Constraints

- $1 \leq T \leq 5$
- $1 \leq N \leq 10^5$
- $-10^9 \leq Xi, Yi, A, B \leq 10^9$
### Sample 1:
Input
Output

```
2
6
1 0
0 2
2 5
4 4
5 0
6 2
3 2
4
5 6
3 5
2 8
-8 -8
0 0
```

```
YES
NO
```

### Explanation:

In the first test case, the king is in cannot move to any valid position In second test case, the king can easily make a valid move.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-17T16:43:36.835Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    ll n,x,y;
	    cin>>n;
	    map<pair<ll,ll>,ll> m;
	    while(n--){
	        cin>>x>>y;
	        m[{x-2,y-1}]++;//all possible moves of knight
	        m[{x-1,y-2}]++;
	        m[{x-2,y+1}]++;
	        m[{x-1,y+2}]++;
	        m[{x+2,y-1}]++;
	        m[{x+1,y-2}]++;
	        m[{x+2,y+1}]++;
	        m[{x+1,y+2}]++;
	    }
	    cin>>x>>y;
	    if(m[{x,y}]!=0){//all possible moves of king
	        if(m[{x-1,y-1}]==0 || m[{x-1,y}]==0 || m[{x-1,y+1}]==0 || m[{x,y-1}]==0 || m[{x,y+1}]==0 || m[{x+1,y-1}]==0 || m[{x+1,y}]==0 || m[{x+1,y+1}]==0)
	            cout<<"NO\n";
	        else
	            cout<<"YES\n";
	    }
	    else
	        cout<<"NO\n";
	}
	return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/KCHESS)