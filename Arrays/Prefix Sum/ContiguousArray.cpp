#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    int maxi = 0, sum = 0;
    unordered_map<int, int> mpp;
    mpp[0] = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += ((nums[i] == 0) ? -1 : 1);

        if (mpp.find(sum) != mpp.end())
        {
            maxi = max(maxi, i - mpp[sum]);
        }
        else
        {
            mpp[sum] = i;
        }
    }

    return maxi;
}

int main()
{
    // 🔹 Example usage:
    vector<int> nums = {0, 1, 0, 1, 1, 0, 0};
    cout << "Maximum length of a contiguous subarray with equal number of 0s and 1s: ";
    cout << findMaxLength(nums) << endl;

    // 📝 Problem:
    // LeetCode 525 – Contiguous Array
    //
    // Given a binary array nums, return the maximum length of a contiguous subarray
    // with an equal number of 0s and 1s.
    //
    // Example:
    // Input: nums = [0,1,0,1,1,0,0]
    // Output: 6
    // Explanation: The subarray [1,0,1,1,0,0] has 3 zeros and 3 ones.
    //
    // Constraints:
    // - 1 <= nums.length <= 10^5
    // - nums[i] is either 0 or 1

    return 0;
}
