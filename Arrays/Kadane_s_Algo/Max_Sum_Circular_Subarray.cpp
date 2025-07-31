// Problem: Maximum Sum Circular Subarray
// Link: https://leetcode.com/problems/maximum-sum-circular-subarray/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Example:
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Circular subarray [3, -2, 1] sums to 2, which is less.
*/

int maxSubarraySumCircular(vector<int> &nums)
{
    int currMax = nums[0], currMin = nums[0];
    int maxSum = nums[0], minSum = nums[0];
    int totSum = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        currMax = max(nums[i], currMax + nums[i]); // Kadane's for max
        maxSum = max(maxSum, currMax);

        currMin = min(nums[i], currMin + nums[i]); // Kadane's for min
        minSum = min(minSum, currMin);

        totSum += nums[i]; // Total sum of array
    }

    // If all elements are negative, circular sum becomes invalid
    if (minSum == totSum)
    {
        return maxSum;
    }

    return max(maxSum, totSum - minSum);
}

int main()
{
    vector<int> nums = {1, -2, 3, -2};
    int result = maxSubarraySumCircular(nums);
    cout << "Maximum circular subarray sum is: " << result << endl;

    return 0;
}
