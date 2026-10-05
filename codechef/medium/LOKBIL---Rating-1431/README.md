# LOKBIL - Rating 1431

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Most Popular Friend

Anna Hazare is a well known social activist in India.

On 5th April, 2011 he started "Lokpal Bill movement".

Chef is very excited about this movement. He is thinking of contributing to it. He gathers his cook-herd and starts thinking about how our community can contribute to this.

All of them are excited about this too, but no one could come up with any idea. Cooks were slightly disappointed with this and went to consult their friends.

One of the geekiest friend gave them the idea of spreading knowledge through Facebook. But we do not want to spam people's wall. So our cook came up with the idea of dividing Facebook users into small friend groups and then identify the most popular friend in each group and post on his / her wall. They started dividing users into groups of friends and identifying the most popular amongst them.

The notoriety of a friend is defined as the averaged distance from all the other friends in his / her group. This measure considers the friend himself, and the trivial distance of '0' that he / she has with himself / herself.

The most popular friend in a group is the friend whose notoriety is least among all the friends in the group.

Distance between X and Y is defined as follows:
Minimum number of profiles that X needs to visit for reaching Y's profile(Including Y's profile). X can open only those profiles which are in the friend list of the current opened profile. For Example:

- Suppose A is friend of B.
- B has two friends C and D.
- E is a friend of D. Now, the distance between A and B is 1, A and C is 2, C and E is 3. So, one of our smart cooks took the responsibility of identifying the most popular friend in each group and others will go to persuade them for posting. This cheeky fellow knows that he can release his burden by giving this task as a long contest problem. Now, he is asking you to write a program to identify the most popular friend among all the friends in each group. Also, our smart cook wants to know the average distance of everyone from the most popular friend.
### Input

Friends in a group are labelled with numbers to hide their Facebook identity. The first line of input contains the number of groups in which users are divided. First line of each group contains the number of friends that belong to that group. ith line of each group contains the space separated friend list of 'i'. You are assured that each friend's profile can be accessed by the profile of every other friend by following some sequence of profile visits.

### Output

Your output contains the most popular friend name label along with the average distance (space separated) from all other friends (including himself / herself) in six digits of precision. There might be multiple most popular friend, in that case output the friend labelled with least number.

### Note:

Each person in a group have atleast one friend and he/she cannot be in his/her own friend list.
Number of friends in a group cannot be more than 100.
There are atmost 100 groups.

### Sample 1:
Input
Output

```
1
6
3
5
1 4
3 5 6
2 4 6
4 5
```

```
4 1.166667
```

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-05T06:02:25.499Z  

```c_cpp
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pr;

int D[101];
// std::vector<pr> E = {};
std::vector<int> E[101];
int main() {
    int g, n; cin >> g; // scanf("%d", &g);
    string ff, nxt;
    int nxti; std::queue<int> Q = {}; int qlen;
    long double resd, tmpd;
    int resp; 
    int cur;
    while (g) {
        g--; cin >> n; // scanf("%d", &n);
        std::getline(std::cin, ff);
        for (int p = 1; p <= n; p++) {
            E[p].clear();
            std::getline(std::cin, ff);
            std::istringstream ss(ff);
            while (ss >> nxt) {
                nxti = std::stoi(nxt);
                E[p].push_back(nxti);
            }
        }
        resd = -1.0; resp = -1;
        for (int p = 1; p <= n; p++) {
            int tmp = 0; 
            memset(D, -1, sizeof(D)); D[p] = 0;
            Q.push(p);
            int curround = 1;
            while (!Q.empty()) {
                qlen = Q.size();
                for (int i = 0; i < qlen; i++) {
                    cur = Q.front(); Q.pop();
                    for (int dd : E[cur]) {
                        if (D[dd] == -1) {
                           tmp += curround;
                           D[dd] = curround;
                           Q.push(dd);
                        }
                    }
                }
                curround++;
            }
            if (resp == -1) {
                resp = p;
                resd = (long double)tmp / (long double)n;
            }
            else {
                tmpd = (long double)tmp / (long double)n;
                if (tmpd < resd) {
                    resp = p;
                    resd = tmpd;
                }
            }
        }
        printf("%d %Lf", resp, resd);
        if (g > 0)
            printf("\n");
    }
    return 0;
 }
```

---

[View on CodeChef](https://www.codechef.com/problems/LOKBIL)