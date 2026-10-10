# TRICKYDL - Rating 1431

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### The Tricky Deal

One of Chef's friends offered him a deal: during $D$ days, they are going to exchange money. For each $i$ ($1 \le i \le D$), on the $i$-th day, Chef's friend would give Chef $A$ rupees, while Chef would give his friend $2^{i-1}$ rupees ($1$ rupee on day $1$, $2$ rupees on day $2$, $4$ rupees on day $3$, and so on). Chef's profit from the deal is the total number of rupees he received from his friend minus the total number of rupees he gave his friend.

Chef decided to ask for your advice before accepting the deal. You want to help him by telling him two numbers $D_1$ and $D_2$, where $D_1$ is the maximum value of $D$ such that Chef should accept the deal, i.e. his profit from the deal is positive if $D = D_1$, and $D_2$ is the value of $D$ that leads to the maximum possible profit for Chef. If there are multiple values of $D$ that lead to the maximum profit, $D_2$ is the smallest of these values.

### Input
- The first line of the input contains a single integer $T$ denoting the number of test cases. The description of $T$ test cases follows.
- The first and only line of each test case contains a single integer $A$.
### Output

For each test case, print a single line containing two space-separated integers $D_1$ and $D_2$.

### Constraints
- $1 \le T \le 100,000$
- $5 \le A \le 10^9$
### Subtasks

 **Subtask #1 (100 points):**  original constraints

### Sample 1:
Input
Output

```
4
5
8
9
1000000000
```

```
4 3
5 3
5 4
35 30
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-10T10:48:50.786Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	ll t;
	cin>>t;
	while(t--){
	 ll a;
	  cin>>a;
	  ll d1=0,sum=0,d2=0;
	   ll i=0;
	   while(true){
	       if(a>pow(2,i)){
	           d2++;
	       }
	       else{
	           break;
	       }
	       ++i;
	   }
	   i=0;
	   while(true){
	       sum += pow(2,i);
	       if(a*(i+1) > sum){
	           d1++;
	       }
	       else{
	           break;
	       }
	       ++i;
	   }
	   
	   
	 cout<<d1<<" "<<d2<<endl;   
	    
	  
	}
	return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/TRICKYDL)