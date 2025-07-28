// ✅ LeetCode: Count Number of Nice Subarrays
// 🎯 Problem:
// Given an array of integers `nums` and an integer `k`,
// return the number of **nice subarrays**.
// A nice subarray is a contiguous subarray that contains exactly `k` odd numbers.

// 💡 Approach:
// - Convert the problem to a prefix sum problem using binary transformation: even -> 0, odd -> 1.
// - Count how many times a prefix sum of (currSum - k) has occurred using a hashmap.
// - For each element, we track the number of subarrays that end at the current index
//   and contain exactly k odd numbers.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int currSum = 0, subArray = 0;
        unordered_map<int, int> preSum;
        preSum[currSum] = 1;

        for (int j = 0; j < nums.size(); j++)
        {
            currSum += nums[j] % 2;

            if (preSum.find(currSum - k) != preSum.end())
            {
                subArray += preSum[currSum - k];
            }

            preSum[currSum]++;
        }

        return subArray;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {1, 1, 2, 1, 1}; // Sample test case
    int k = 3;

    int result = sol.numberOfSubarrays(nums, k);
    cout << "Number of nice subarrays with exactly " << k << " odd numbers: " << result << endl;

    return 0;
}
