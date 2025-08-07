// ✅ Problem Recap
// Given points, an array where each element represents the start and end of a balloon, return the minimum number of arrows required to burst all the balloons.

// 📥 Example Input

// points = [[10,16],[2,8],[1,6],[7,12]]
// 🔧 Explanation:
// We can shoot one arrow at 6 to burst [1,6], [2,8], [7,12] and another at 16 to burst [10,16].
// ✅ Answer: 2 arrows.

// ✅ Complete Code (for VS Code)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
         {
             return a[1] < b[1]; // Sort by end of interval
         });

    int arrow = 1;           // At least one arrow needed
    int prev = points[0][1]; // First arrow at the end of first balloon

    for (int i = 1; i < points.size(); i++)
    {
        // If current balloon starts after the previous arrow, we need a new arrow
        if (points[i][0] > prev)
        {
            arrow++;
            prev = points[i][1];
        }
    }
    return arrow;
}

int main()
{
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};

    int result = findMinArrowShots(points);

    cout << "Minimum arrows required: " << result << endl;

    return 0;
}

// 💻 Output

// Minimum arrows required: 2