// Problem: Maximum Product Subarray
// Link: https://leetcode.com/problems/maximum-product-subarray/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Example:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: The subarray [2,3] has the largest product 6.
*/

int maxProduct(vector<int> &nums)
{
    int n = nums.size(), l = 0, r = 0, res = nums[0];

    for (int i = 0; i < n; i++)
    {
        l = (l ? l : 1) * nums[i];         // Forward pass
        r = (r ? r : 1) * nums[n - 1 - i]; // Backward pass
        res = max(res, max(l, r));         // Track maximum
    }

    return res;
}

int main()
{
    vector<int> nums = {2, 3, -2, 4};
    int result = maxProduct(nums);
    cout << "Maximum product subarray is: " << result << endl;

    return 0;
}
