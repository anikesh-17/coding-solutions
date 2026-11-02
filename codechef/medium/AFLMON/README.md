# AFLMON

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Power Badges

There are $N$ players in a game. Player $i$ has a power level of $A_i$.

A player earns a badge if the number of players with power levels less than or equal to their own is strictly greater than the number of players with higher power levels. The player themselves is included in the first count.

Find the number of players who earn a badge.

### Input Format
- The first line contains an integer $T$, the number of test cases.
- For each test case: The first line contains an integer $N$, the number of players. The second line contains $N$ space-separated integers $A_1,A_2,\ldots,A_N$, the power levels of the players.
### Output Format

For each test case, print the number of players who earn a badge on a separate line.

### Constraints
- $1 \le T \le 1000$
- $1 \le N \le 100$
- $0 \le A_i \le 100$
### Sample 1:
Input
Output

```
3
5
4 1 4 2 5
4
10 20 30 40
6
7 7 7 7 7 7
```

```
3
2
6
```

### Explanation:
- Test case $1$: Each player with power level $4$ has $4$ players with power levels less than or equal to their own and $1$ with a higher power level. Both earn badges. The player with power level $5$ also earns a badge, giving a total of $3$.
- Test case $2$: The players with power levels $30$ and $40$ earn badges. For the player with power level $20$, both counts are $2$, so the strict inequality does not hold.
- Test case $3$: Each player has $6$ players with power levels less than or equal to their own and none with a higher power level. All $6$ earn badges.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-02T14:41:21.317Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

class Anikesh{
  public:
  Anikesh(){
      output();
  }
  private:
  void output(){
      int t;
      cin>>t;
      while(t--){
          int n;
          cin>>n;
          vector<int> vec(n);
          for (int i = 0; i < n; i++) {
              cin>>vec[i];
          }
          cout << chk(vec, n) << endl;
      }
  }
  int chk(vector<int> vec, int n){
    //   sort(vec.begin(), vec.end());
    //   for(int i = n-1; i>=0; i--){
             
    //   }
    int maxi = *std::max_element(vec.begin(), vec.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if(vec[i] == maxi) cnt++;
    }
    return cnt;
  }
};

int main() {
	// your code goes here
	Anikesh obj;

}

```

---

[View on CodeChef](https://www.codechef.com/problems/AFLMON)