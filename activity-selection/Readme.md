# Activity Selection Problem
The Activity Selection Problem is a classic optimization problem that involves selecting the maximum number of activities that don't overlap, given their start and finish times. This problem is commonly solved using a Greedy Algorithm.

## Problem
Given `n` activities with start and finish times, select the maximum number of non-overlapping activities.

## Example

| Activity | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |
|----------|---|---|---|---|---|---|---|---|---|----|----|
| Start    | 1 | 3 | 0 | 5 | 5 | 6 | 8 | 8 | 2 | 12 | 2  |
| Finish   | 4 | 5 | 6 | 7 | 9 | 10| 9 | 11| 14| 16 | 12 |

### Greedy Approach


1. Sort activities by **finish time**.
2. Select the first activity.
3. For each next activity, if its start time ≥ finish time of the last selected activity, select it.

#### Sorted Activities by Finish Time:

| Activity | 1 | 4 | 8 | 11 |
|----------|---|---|---|----|
| Start    | 1 | 5 | 8 | 12 |
| Finish   | 4 | 7 | 11| 16 |

#### Selected Activities:

```css
A = {a1, a4, a8, a11}
```

### Dynamic programming approch

This DP approch solves the problem by trying **all valid combinationa** of activities using **optimal substructure** and **overlapping subproblems**.

1. For each pair (i, j), try every possible k such that:

`finish[i] ≤ start[k]` and `finish[k] ≤ start[j]`

```python
dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + 1)
```

>[!Note]
> `dp[i][j]` represent the maximum number of non-overlapping between `i` and `j`.

#### Selected Activities:

```css
A = {a1, a4, a8, a11}
```
## Conclusion

The **Greedy Algorithm** is the **best and optimal solution** for the standard Activity Selection Problem because:

- It’s fast and efficient (`O(n log n)`)
- It gives the correct answer due to the problem's **structure**
- There’s no benefit in using slower methods like DP here

>[!Importent]
>When Greedy Fails?
> - Activities have **weights or profits** (e.g. maximize total profit)
> - You need to minimize **idle time**, not just maximize count
> - You want to minimize the **number of resources/rooms**

## Resources

Here are some of the sources I used to learn:

- [tutorialspoint](https://www.tutorialspoint.com/activity-selection-problem) 

- [heycoach](https://heycoach.in/blog/activity-selection-with-dynamic-programming/)  

- [walkccc](https://walkccc.me/CLRS/Chap16/16.1/)  
