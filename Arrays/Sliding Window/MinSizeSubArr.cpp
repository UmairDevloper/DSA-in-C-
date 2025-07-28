// ✅ LeetCode: 209. Minimum Size Subarray Sum
// 🎯 Problem:
// Given an array of positive integers `nums` and an integer `target`,
// return the minimal length of a contiguous subarray of which the sum is
// greater than or equal to `target`. If there is no such subarray, return 0.

// 💡 Approach (Sliding Window):
// - Use two pointers (`l` and `r`) to define a sliding window.
// - Expand the window by moving `r` and adding `nums[r]` to `windowSum`.
// - When `windowSum` is greater than or equal to `target`,
//   shrink the window from the left and update the minimum length.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int l = 0, windowSum = 0;
        int ans = INT_MAX;

        for (int r = 0; r < nums.size(); r++)
        {
            windowSum += nums[r];

            while (windowSum >= target)
            {
                ans = min(ans, r - l + 1);
                windowSum -= nums[l];
                l++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {2, 3, 1, 2, 4, 3}; // Example test case
    int target = 7;

    int result = sol.minSubArrayLen(target, nums);
    cout << "Minimum size of subarray with sum ≥ " << target << ": " << result << endl;

    return 0;
}
