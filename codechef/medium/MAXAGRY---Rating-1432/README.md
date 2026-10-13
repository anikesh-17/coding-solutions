# MAXAGRY - Rating 1432

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Maximum Angriness

Alice and Bob were playing a game yet again but this time, Bob already lost the game. Now he wants to take revenge.

Bob saw a jigsaw puzzle which was solved by Alice and decided to jumble the puzzle pieces again. There are $N$ puzzle pieces in a line numbered from $1$ to $N$ in increasing order and he has $K$ minutes before Alice catches him.
Bob can  **swap any two pieces**  of the puzzle. Each swap takes $1$ minute, and so Bob can make  **at most**  $K$ swaps.

Let $A_i$ denote the piece in the $i$-th position after Bob finishes making his swaps.

Alice's  *angriness*  is defined to be the number of pairs $(i, j)$ such that $1 \leq i \lt j \leq N$ and $A_i \gt A_j$.

Bob would like to make Alice as angry as possible, so he asks for your help: if he performs his swaps optimally, what is the  **maximum  *angriness***  he can achieve?

### Input Format
- The first line of input contains an integer $T$, denoting the number of test cases.
- The first and only line of each test case contains two space-separated integers $N$ and $K$: the number of pieces and the number of swaps Bob can make.
### Output Format
- For each test case, output on a new line a single integer: Alice's maximum possible angriness.
### Constraints
- $1 \leq T \leq 10^5$
- $1 \leq N \leq 10^{9}$
- $1 \leq K \leq 10^{9}$
### Sample 1:
Input
Output

```
4
7 3
1 4
8 2
5 3

```

```
21
0
22
10

```

### Explanation:

 **Test case $1$:**  $N = 7$, so the pieces are initially arranged as $[1, 2, 3, 4, 5, 6, 7]$. Bob can make $K = 3$ swaps. One optimal way of swapping is as follows:

- First, swap $2$ and $6$. Now the pieces are $[1, 6, 3, 4, 5, 2, 7]$
- Next, swap $1$ and $7$. Now the pieces are $[7, 6, 3, 4, 5, 2, 1]$
- Finally, swap $3$ and $5$. Now the pieces are $[7, 6, 5, 4, 3, 2, 1]$

The angriness of this sequence is $21$, which is the maximum possible.

 **Test case $2$:**  $N = 1$, so no swaps can be made. The answer is always $0$.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-13T10:53:20.117Z  

```c_cpp
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    long long n,k;
	    cin>>n>>k;
	    long long no=n/2;
	   
	    if(n==1 ){
	        cout<<0<<endl;
	    }
	        else if(no<=k){
	        long long ans=n*(n-1);
	        cout<<ans/2<<endl;
	    }
	    else if(no>k){
	        long long ans=(n*(n-1))/2;
	        long long me=n-(2*k);
	        long long sum_me=(me*(me-1))/2;
	        ans=ans-sum_me;
	        cout<<ans<<endl;
	    }
	}
	return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/MAXAGRY)