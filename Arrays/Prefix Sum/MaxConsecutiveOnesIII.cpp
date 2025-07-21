#include <iostream>
#include <vector>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int left = 0;

    for (int right = 0; right < n; right++)
    {
        if (nums[right] == 0)
        {
            k--;
        }

        if (k < 0)
        {
            if (nums[left] == 0)
            {
                k++;
            }
            left++;
        }
    }

    return n - left;
}

int main()
{
    // 🔹 Example usage:
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    cout << "Longest subarray with at most " << k << " zeros flipped to 1s: ";
    cout << longestOnes(nums, k) << endl;

    // 📝 Problem:
    // LeetCode 1004 - Max Consecutive Ones III
    //
    // Given a binary array `nums` and an integer `k`, return the maximum number of consecutive 1s
    // in the array if you can flip at most `k` 0s to 1s.
    //
    // Example:
    // Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
    // Output: 6
    // Explanation: Replace the two 0s at indices 5 and 10 with 1s to form [1,1,1,0,0,1,1,1,1,1,1]
    //              which has 6 consecutive 1s.
    //
    // Constraints:
    // - 1 <= nums.length <= 10^5
    // - nums[i] is either 0 or 1
    // - 0 <= k <= nums.length

    return 0;
}
