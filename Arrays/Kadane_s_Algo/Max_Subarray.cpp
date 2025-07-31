// Problem: Maximum Subarray
// Link: https://leetcode.com/problems/maximum-subarray/
// Algorithm: Kadane’s Algorithm

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/*
Example:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum = 6.
*/

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int currSum = 0, maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        currSum += nums[i];                 // Add current element to current sum
        maxSum = max(maxSum, currSum);      // Update max if needed

        if (currSum < 0) {
            currSum = 0;                    // Reset if sum goes negative
        }
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = maxSubArray(nums);
    cout << "Maximum subarray sum is: " << result << endl;

    return 0;
}
