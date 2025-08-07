// 🔄 Problem Summary
// You're given an array of intervals. The goal is to remove the minimum number of intervals so that the rest do not overlap.

// 📥 Sample Input
// cpp
// Copy
// Edit
// intervals = [[1,2],[2,3],[3,4],[1,3]]
// 💡 Optimal solution keeps: [1,2], [2,3], [3,4]
// ❌ Remove: [1,3]
// ✅ Answer: 1 removal

// ✅ Full C++ Code(VS Code Ready)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Custom comparator to sort intervals by their end times
static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

// Function to return the minimum number of intervals to remove
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), cmp); // Sort by end time

    int prev = 0;  // Index of last selected interval
    int count = 1; // At least one interval can always be kept

    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] >= intervals[prev][1])
        {
            prev = i; // Select current interval
            count++;  // Increase count of non-overlapping intervals
        }
    }

    return n - count; // Number of intervals to remove
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    int result = eraseOverlapIntervals(intervals);

    cout << "Minimum intervals to remove: " << result << endl;

    return 0;
}

// 🖨️ Output

// Minimum intervals to remove: 1