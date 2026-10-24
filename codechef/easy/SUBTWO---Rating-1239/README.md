# SUBTWO - Rating 1239

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Least Common Anagram

You are given $N$ strings consisting of lowercase English letters.

Your goal is to find the  **longest string**  $W$ such that the letters of $W$ (including duplicates) appear in every string in the given set.

- Specifically, if a letter appears $k$ times in $W$, it must appear at least $k$ times in each of the $N$ input strings.

If there are multiple such strings of the maximum possible length, choose the one that is  **lexicographically smallest**  (i.e., in alphabetical order). If no such non-empty string can be formed, output `no such string` (without quotes).

 **Note on Lexicographical Order:** 
A string $X$ is lexicographically smaller than a string $Y$ if at the first index where they differ, the character in $X$ is alphabetically smaller than the corresponding character in $Y$. If they match completely but differ in length, the shorter string is lexicographically smaller (e.g., `"abc" < "abd"` and `"abc" < "abcd"`).

### Input Format
- The first line contains a single integer $N$ — the number of strings.
- The next $N$ lines each contain a non-empty string consisting only of lowercase English letters (a–z).
### Output Format
- Output the longest lexicographically smallest string that satisfies the condition.
- If no such non-empty string exists, output no such string.
### Constraints
- $1 \le N \le 100$
- The length of each input string is at most $100$.
- All strings contain only lowercase English letters (a–z).
### Sample 1:
Input
Output

```
3
remote
meteor
term
```

```
emrt
```

### Explanation:

The characters `'e'`, `'m'`, `'r'`, and `'t'` each appear at least once in all three input strings (`remote`, `meteor`, and `term`). Sorting these common letters in alphabetical order yields `emrt`, which is the lexicographically smallest common string of maximum length.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-10-24T16:00:33.526Z  

```c_cpp
#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // init minCount with largeValue
    vector<int> minCnt(26,1e9);

    for(int i=0; i<n;i++) {
        string s;
        cin >> s;

        vector<int> cnt(26, 0);
        for (char c: s) {
            cnt[c-'a'] += 1;

        }

        for (int i=0;i<26;i++) {
            minCnt[i] = min(minCnt[i], cnt[i]);
        }


    }

    // create result
    string result = "";
    for (int j = 0; j < 26; j++) {
        for (int k = 0; k < minCnt[j]; k++) {
            result += char('a' + j);
        }
    }

    if (result.empty()) {
        cout << "no such string" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/SUBTWO)