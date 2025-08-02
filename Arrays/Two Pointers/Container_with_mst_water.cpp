// ✅ Problem: Container With Most Water (LeetCode #11)
// 🔗 https://leetcode.com/problems/container-with-most-water/
// 🧠 Goal: Given an array of heights, find the max water container using 2 lines.

// 🔍 Example:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The container formed between height[1]=8 and height[8]=7 gives max area:
// Area = min(8, 7) * (8 - 1) = 7 * 7 = 49

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ✅ Core Logic: Two-pointer approach from both ends
int maxArea(vector<int> &height)
{
    int n = height.size();
    int max_water = 0;
    int l = 0, r = n - 1;

    while (l < r)
    {
        int width = r - l;
        int min_hgt = min(height[l], height[r]);
        int area = width * min_hgt;
        max_water = max(max_water, area);

        // Move the shorter line inward
        if (height[l] < height[r])
            l++;
        else
            r--;
    }

    return max_water;
}

// 🧪 Main function for testing
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int result = maxArea(height);

    cout << "Maximum water that can be contained is: " << result << endl;

    return 0;
}
