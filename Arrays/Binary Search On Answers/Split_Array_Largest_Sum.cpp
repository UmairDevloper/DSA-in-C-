#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Split Array Largest Sum
    --------------------------------
    Given an integer array `nums` and an integer `k`, split the array into `k` or fewer
    non-empty subarrays so that the **largest sum among these subarrays is minimized**.

    Return the minimal largest sum possible.

    Example:
    --------
    nums = [7,2,5,10,8], k = 2
    Possible splits:
        - [7,2,5] and [10,8] → largest sum = max(14,18) = 18
        - [7,2] and [5,10,8] → largest sum = max(9,23) = 23
    The minimum possible largest sum = 18.

    Approach (Binary Search on Answer):
    ------------------------------------
    1. The **minimum possible largest sum** is the maximum element in `nums` (can't be smaller).
    2. The **maximum possible largest sum** is the sum of all elements (no split).
    3. Binary search between these two limits to find the minimal feasible largest sum.
    4. To check feasibility (`isFeasible`):
        - Iterate over `nums`, forming subarrays without exceeding `maxSum`.
        - If more than `k` subarrays are required → Not feasible.
*/

bool isFeasible(vector<int> &nums, int maxSum, int k)
{
    int count = 1;      // Number of subarrays
    int currentSum = 0; // Current subarray sum

    for (int num : nums)
    {
        currentSum += num;
        if (currentSum > maxSum)
        {
            // Need to start a new subarray
            count++;
            currentSum = num;
            if (count > k)
                return false; // Too many subarrays
        }
    }
    return true;
}

int splitArray(vector<int> &nums, int k)
{
    int low = 0, high = 0;

    // Set binary search boundaries
    for (int num : nums)
    {
        low = max(low, num); // largest element
        high += num;         // sum of all elements
    }

    int ans = high; // Initialize answer to the largest possible sum
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isFeasible(nums, mid, k))
        {
            ans = mid;
            high = mid - 1; // Try smaller largest sum
        }
        else
        {
            low = mid + 1; // Need larger largest sum
        }
    }
    return ans;
}

/*
    Example Runs:
    -------------
    1) nums = [7,2,5,10,8], k = 2 → Output: 18
    2) nums = [1,2,3,4,5], k = 2  → Output: 9
    3) nums = [1,4,4], k = 3      → Output: 4
*/

int main()
{
    vector<int> nums1 = {7, 2, 5, 10, 8};
    cout << "Example 1: " << splitArray(nums1, 2) << endl; // Expected: 18

    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << "Example 2: " << splitArray(nums2, 2) << endl; // Expected: 9

    vector<int> nums3 = {1, 4, 4};
    cout << "Example 3: " << splitArray(nums3, 3) << endl; // Expected: 4

    return 0;
}
