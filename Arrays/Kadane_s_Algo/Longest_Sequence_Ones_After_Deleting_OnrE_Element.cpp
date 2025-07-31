// Problem: Longest Subarray of 1's After Deleting One Element
// Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
// Sliding Window Approach

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Example:
Input: nums = [1,1,0,1]
Output: 3
Explanation: Delete the 0 to get [1,1,1]. The longest subarray of 1s is length 3.
*/

int longestSubarray(vector<int> &nums)
{
    int zeroCnt = 0;
    int currWindow = 0;
    int i = 0;

    for (int j = 0; j < nums.size(); j++)
    {
        zeroCnt += (nums[j] == 0); // Count how many zeros in the window

        // Shrink window if more than 1 zero
        while (zeroCnt > 1)
        {
            zeroCnt -= (nums[i] == 0);
            i++;
        }

        // Update max window length
        currWindow = max(currWindow, j - i);
    }

    return currWindow;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1};
    int result = longestSubarray(nums);
    cout << "Longest subarray of 1s after deleting one element: " << result << endl;

    return 0;
}
