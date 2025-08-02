// ✅ Problem: 3Sum (LeetCode #15)
// 🔗 https://leetcode.com/problems/3sum/
// 🧠 Goal: Find all unique triplets in the array that sum up to zero.

// 🔍 Example:
// Input: nums = {-1, 0, 1, 2, -1, -4}
// Sorted:       {-4, -1, -1, 0, 1, 2}
// Output: [[-1, -1, 2], [-1, 0, 1]]
// Explanation: Triplets that sum to 0 without duplicates.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ✅ Core Logic: Sorting + Two-Pointer
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;

    for (int i = 0; i < nums.size() - 2; i++)
    {
        // Avoid duplicates for the first element
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int low = i + 1, high = nums.size() - 1;
            int sum = 0 - nums[i];

            while (low < high)
            {
                if (nums[low] + nums[high] == sum)
                {
                    res.push_back({nums[i], nums[low], nums[high]});

                    // Skip duplicates for low and high
                    while (low < high && nums[low] == nums[low + 1])
                        low++;
                    while (low < high && nums[high] == nums[high - 1])
                        high--;

                    low++;
                    high--;
                }
                else if (nums[low] + nums[high] < sum)
                    low++;
                else
                    high--;
            }
        }
    }

    return res;
}

// 🧪 Main function for testing
int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = threeSum(nums);

    cout << "Triplets summing to 0 are:\n";
    for (auto triplet : result)
    {
        cout << "[ ";
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
