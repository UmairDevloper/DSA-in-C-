#include <bits/stdc++.h>
using namespace std;

/*
=====================================================================
Problem: Maximum Sum Rectangle in a 2D Matrix (Using 2D Prefix Sum)
=====================================================================

Statement:
----------
Given a 2D matrix (with positive, negative, or zero values), find the
contiguous sub-rectangle (any set of continuous rows & columns) having
the maximum possible sum, and return that sum (optionally also its bounds).

Here we solve it using a **2D Prefix Sum** so we can query any rectangle
sum in O(1) and then brute-force over all rectangles in O(R^2 * C^2).

(For a faster O(C^2 * R) solution, see the Kadane-on-compressed-columns
approach. But this file demonstrates the pure prefix-sum way.)

---------------------------------------------------------------------
2D Prefix Sum:
--------------
Let ps be a 2D prefix sum such that:
  ps[i][j] = sum of all elements in rectangle (0,0) .. (i-1, j-1)
with ps having dimension (R+1) x (C+1), 1-based for convenience.

Then, for a rectangle (r1..r2, c1..c2) 0-based inclusive:
  sum = ps[r2+1][c2+1]
      - ps[r1][c2+1]
      - ps[r2+1][c1]
      + ps[r1][c1]

---------------------------------------------------------------------
Time Complexity:
  - Building prefix sum: O(R * C)
  - Enumerating all rectangles: O(R^2 * C^2)
  - Each rectangle sum query: O(1)
Total: O(R^2 * C^2)

Space Complexity:
  - O(R * C) for the prefix sum matrix

=====================================================================
*/

int findSum(int up, int left, int down, int right,
            vector<vector<int>> &pref)
{

    // Start with the sum of the entire submatrix (0, 0) to (down, right)
    int sum = pref[down][right];

    // Subtract the area to the left of the submatrix, if it exists
    if (left - 1 >= 0)
    {
        sum -= pref[down][left - 1];
    }

    // Subtract the area above the submatrix, if it exists
    if (up - 1 >= 0)
    {
        sum -= pref[up - 1][right];
    }

    // Add back the overlapping area that was subtracted twice
    if (up - 1 >= 0 && left - 1 >= 0)
    {
        sum += pref[up - 1][left - 1];
    }

    return sum;
}

// function to find the maximum sum rectangle in a 2D matrix
int maxRectSum(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    // Initialize the prefix sum matrix
    vector<vector<int>> pref(n, vector<int>(m, 0));

    // Row-wise sum
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            pref[i][j] = mat[i][j];
            if (j - 1 >= 0)
            {
                pref[i][j] += pref[i][j - 1];
            }
        }
    }

    // Column-wise sum
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i - 1 >= 0)
            {
                pref[i][j] += pref[i - 1][j];
            }
        }
    }

    int maxSum = INT_MIN;

    for (int up = 0; up < n; up++)
    {
        for (int left = 0; left < m; left++)
        {
            for (int down = up; down < n; down++)
            {
                for (int right = left; right < m; right++)
                {

                    // Find the sum of submatrix(up, right, down, left)
                    int sum = findSum(up, left, down, right, pref);

                    // Update maxSum if sum > maxSum.
                    if (sum > maxSum)
                    {
                        maxSum = sum;
                    }
                }
            }
        }
    }

    return maxSum;
}

int main()
{
    vector<vector<int>> mat = {{1, 2, -1, -4, -20},
                               {-8, -3, 4, 2, 1},
                               {3, 8, 10, 1, 3},
                               {-4, -1, 1, 7, -6}};
    cout << maxRectSum(mat) << endl;
}
