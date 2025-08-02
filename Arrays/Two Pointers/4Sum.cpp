// ✅ Problem: 4Sum (LeetCode #18)
// 🔗 https://leetcode.com/problems/4sum/
// 🧠 Goal: Find all unique quadruplets in the array that sum to the given target.

// 🔍 Example:
// Input: nums = [1, 0, -1, 0, -2, 2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ✅ Core Logic: Two Pointers + Sorting + Duplicate Skipping
vector<vector<int>> fourSum(vector<int> &nums, long long target)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    int n = nums.size();
    if (nums.empty())
        return res;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            int left = j + 1;
            int right = n - 1;
            long long val = target - nums[i] - nums[j];

            while (left < right)
            {
                long long two_sum = nums[left] + nums[right];

                if (two_sum < val)
                {
                    left++;
                }
                else if (two_sum > val)
                {
                    right--;
                }
                else
                {
                    vector<int> quadVal(4, 0);
                    quadVal[0] = nums[i];
                    quadVal[1] = nums[j];
                    quadVal[2] = nums[left];
                    quadVal[3] = nums[right];
                    res.push_back(quadVal);

                    // Skip duplicates
                    while (left < right && nums[left] == quadVal[2])
                        left++;
                    while (left < right && nums[right] == quadVal[3])
                        right--;
                }
            }

            // Skip duplicates for j
            while (j + 1 < n && nums[j + 1] == nums[j])
                ++j;
        }

        // Skip duplicates for i
        while (i + 1 < n && nums[i + 1] == nums[i])
            ++i;
    }

    return res;
}

// 🧪 Main function to test the implementation
int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    long long target = 0;

    vector<vector<int>> result = fourSum(nums, target);

    cout << "Quadruplets that sum to " << target << ":\n";
    for (auto quad : result)
    {
        cout << "[";
        for (int i = 0; i < 4; ++i)
        {
            cout << quad[i];
            if (i < 3)
                cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
