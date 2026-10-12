# UNQEQ - Rating 1431

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Balanced and Unique Arrays

For a positive, $\textbf{even}$ integer $N$, we call a pair of arrays $A$ and $B$ to be  **interesting**  if they satisfy the following conditions :

- $|A| = |B| = N/2$ i.e. the length of array $A$ is equal to the length of array $B$.
- Each integer from $1$ to $N$ occurs exactly once in exactly one of the arrays.
- The $i^{th}$ prefix sum of $A$ is not equal to $i^{th}$ prefix sum of $B$ for all $1 \leq i \leq N/2-1$. Formally, $\displaystyle \sum_{j = 1}^{i} A_j$ != $\displaystyle \sum_{j = 1}^{i} B_j$ for all $1 \leq i \leq N/2 - 1$
- Sum of all elements in $A$ is equal to sum of all elements in $B$ i.e. $\displaystyle \sum_{j = 1}^{N/2} A_j = \sum_{j = 1}^{N/2} B_j$

You are given a positive, even integer $N$. If there exists an  **interesting**  pair of arrays, then print "YES" followed by an interesting pair for this given $N$. If there exists multiple  **interesting**  pairs of arrays for given $N$, you can print any. Print "NO" in a single line if no such pair exists.

### Input Format
- First line of input will contain $T$, the number of test cases. Then the test cases follow.
- Each test case contains a single line of input, the integer $N$.
### Output Format

For each test case, if there exists an  **interesting**  pair of arrays, say $(A, B)$, then in the first line print "YES", in the second line print array $A$ separated by spaces, and in third line print array $B$ separated by spaces. Print "NO" in a single line if no such pair exists. If there are multiple answers, print any of them.

### Constraints
- $1 \leq T \leq 10^5$
- $1 \leq N \leq 10^5$
- $N$ is guaranteed to be even.
- Sum of $N$ over all test cases doesn't exceed $10^6$
### Subtasks
- Subtask 1 (100 points): Original constraints
### Sample 1:
Input
Output

```
2
2
4
```

```
NO
YES
1 4
2 3
```

### Explanation:

 **Test case 2:**  Consider $A = [1, 4]$ and $B = [2, 3]$. Every integer from $1$ to $4$ occurs exactly once in exactly one of the arrays. Also, $1$st prefix sum of $A$ is not equal to $1$st prefix sum of $B$ ($1 \neq 2$). And sum of the elements is equal to $5$ for both arrays. So, $(A, B)$ is an interesting pair.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-12T13:23:07.747Z  

```c_cpp
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() 
{
	ll t,n,i,j,k;
	cin >> t;
	while(t--)
	{
	    cin >> n;
	    if(n%4)
	        cout << "NO\n";
	    else
	    {
	        vector<ll>a,b;
	        cout << "YES\n";
	        i=1ll;
	        j=n;
	        while(i<=j)
	        {
	           // cout << i << " " << j << " ";
	            a.push_back(i);
	            a.push_back(j);
	            i+=2;
	            j-=2;
	        }
	        sort(a.begin(),a.end());
	        for(auto x:a)
	            cout << x << " ";
	        cout << "\n";
	        i=2ll;
	        j=n-1;
	        while(i<=j)
	        {
	           // cout << i << " " << j << " ";
	            b.push_back(i);
	            b.push_back(j);
	            i+=2;
	            j-=2;
	        }
	        sort(b.begin(),b.end());
	        for(auto x:b)
	            cout << x << " ";
	        cout << "\n";
	    }
	}
	return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/UNQEQ)