# WINLEAGUE - Rating 520

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

### Win the league

In the Premier League, two teams — $\text{Team A}$ and $\text{Team M}$ — are competing for the title.

You are given the final points scored by both teams:

- If Team A has more points, Team A wins.
- If Team M has more points, Team M wins.
- If both teams have equal points, the league ends in a DRAW.

Your task is to determine the winner of the league.

## Function Declaration
### Function Name

$findLeagueWinner$ – Determines which team wins the Premier League based on their final points.

### Parameters
- $A$ : An integer representing the points scored by Team A.
- $M$ : An integer representing the points scored by Team M.
### Return Value
- Returns a string — $"TEAM\ A"$ if Team A has more points. $"TEAM\ M"$ if Team M has more points. $"DRAW"$ if both teams have equal points.
## Constraints
- $0 \le A, M \le 200$

 **The input and output formats provided below are only for testing with custom inputs. You only need to return the value. Printing is handled by the driver code.** 

### Input Format

A single line containing two space-separated integers:

- $A$ — points scored by Team A
- $M$ — points scored by Team M
### Output Format

Print one of the following:

- $"TEAM\ A"$ if Team A wins
- $"TEAM\ M"$ if Team M wins
- $"DRAW"$ if both teams have equal points
### Sample 1:
Input
Output

```
90 84
```

```
TEAM A
```

### Explanation:

Team A has more points than Team M.

### Sample 2:
Input
Output

```
78 81
```

```
TEAM M
```

### Explanation:

Team M has more points than Team A.

### Sample 3:
Input
Output

```
88 88
```

```
DRAW
```

### Explanation:

Both teams have equal points, so the league ends in a draw.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-11-28T14:28:57.533Z  

```c_cpp
string findLeagueWinner(int A, int M) {
    // write your code here 
    if(A>M ) return "TEAM A";
    if(M>A) return "TEAM M";
    return "DRAW";
}
```

---

[View on CodeChef](https://www.codechef.com/problems/WINLEAGUE)