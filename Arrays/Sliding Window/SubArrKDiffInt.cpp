// ✅ LeetCode: Subarrays with Exactly K Different Integers
// 🎯 Problem:
// Given an array of integers `nums` and an integer `k`, return the number of subarrays
// that contain exactly `k` different integers.

// 💡 Approach:
// Use the sliding window technique to count the number of subarrays with at most `k`
// distinct integers, and subtract the count of subarrays with at most `k-1` distinct integers.
// This gives the number of subarrays with **exactly** `k` distinct integers.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to count subarrays with at most k distinct integers
    int slidingWinAtMst(vector<int> &nums, int k)
    {
        int l = 0, total = 0;
        unordered_map<int, int> freq;

        for (int r = 0; r < nums.size(); r++)
        {
            freq[nums[r]]++;

            while (freq.size() > k)
            {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0)
                {
                    freq.erase(nums[l]);
                }
                l++;
            }

            total += (r - l + 1); // Count valid subarrays ending at r
        }

        return total;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return slidingWinAtMst(nums, k) - slidingWinAtMst(nums, k - 1);
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;

    int result = sol.subarraysWithKDistinct(nums, k);
    cout << "Number of subarrays with exactly " << k << " distinct integers: " << result << endl;

    return 0;
}
