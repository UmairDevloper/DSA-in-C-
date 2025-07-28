// ✅ LeetCode: Longest Subarray With At Most K Frequency
// 🎯 Problem:
// Given an integer array `nums` and an integer `k`,
// return the length of the longest subarray where the frequency
// of **any** element is less than or equal to `k`.

// 💡 Approach:
// Sliding window with a frequency hashmap.
// - Expand the window with `i`.
// - If the current number's frequency exceeds `k`, shrink the window from the left using `j`.
// - Track the maximum window size where all frequencies ≤ k.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int cnt = 0, j = -1;
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;

            while (freq[nums[i]] > k)
            {
                j++;
                freq[nums[j]]--;
            }

            cnt = max(cnt, i - j); // i - j gives the current valid window length
        }

        return cnt;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 2, 1, 2, 3, 1, 1};
    int k = 2;

    int result = sol.maxSubarrayLength(nums, k);
    cout << "Maximum length of subarray with frequency at most " << k << " is: " << result << endl;

    return 0;
}
