#include <bits/stdc++.h>
using namespace std;

/*
========================================================
Problem: Range Addition  (LeetCode 370)
Link   : https://leetcode.com/problems/range-addition/
========================================================

Statement:
---------
You are given an integer n and an array of m update operations, where each update is represented
as a triplet [startIndex, endIndex, inc]. Apply each update to an initially all-zero array of length n,
where inc is added to each element of the subarray nums[startIndex ... endIndex] (inclusive).
Return the final array after all updates.

Example:
--------
Input:
  n = 5
  updates = [[1,3,2],[2,4,3],[0,2,-2]]

Process:
  Start: [ 0,  0,  0,  0,  0]
  +2 on [1..3]: [ 0,  2,  2,  2,  0]
  +3 on [2..4]: [ 0,  2,  5,  5,  3]
  -2 on [0..2]: [-2, 0,  3,  5,  3]

Output:
  [-2, 0, 3, 5, 3]

Constraints (typical for the problem):
--------------------------------------
- 1 <= n <= 10^5 (or more)
- 0 <= updates.size() <= 10^5
- 0 <= startIndex <= endIndex < n
- -10^5 <= inc <= 10^5

--------------------------------------------------------
Intuition:
----------
Applying each update by iterating through the entire [l..r] range would be O(n * m), which is too slow.

Instead, we use a **difference array**:
- For an increment on [l..r] by inc:
    diff[l]   += inc
    diff[r+1] -= inc   (if r+1 < n)
- After processing all updates, take the **prefix sum** of diff to get the final array.

This turns the updates from O(length of range) to O(1) each, and we only do one O(n) pass at the end.

--------------------------------------------------------
Approach:
---------
1) Create an array diff of size n initialized with 0.
2) For each update [l, r, inc]:
     diff[l]   += inc
     if (r + 1 < n) diff[r + 1] -= inc
3) Build the result by computing prefix sums of diff.

--------------------------------------------------------
Time Complexity:
----------------
- Building diff through all updates: O(m)
- Computing final array via prefix sum: O(n)
Total: O(n + m)

Space Complexity:
-----------------
O(n) for the diff/result array.

========================================================
*/

vector<int> getModifiedArray(int length, vector<vector<int>> &updates)
{
    vector<int> d(length);
    for (auto &e : updates)
    {
        int l = e[0], r = e[1], c = e[2];
        d[l] += c;
        if (r + 1 < length)
            d[r + 1] -= c;
    }
    for (int i = 1; i < length; ++i)
        d[i] += d[i - 1];
    return d;
}

int main()
{
    // Sample test
    int n = 5;
    vector<vector<int>> updates = {
        {1, 3, 2},
        {2, 4, 3},
        {0, 2, -2}};

    vector<int> ans = getModifiedArray(n, updates);

    cout << "Final array: ";
    for (int x : ans)
        cout << x << " ";
    cout << "\n";

    return 0;
}
