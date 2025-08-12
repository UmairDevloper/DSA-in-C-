#include <bits/stdc++.h>
using namespace std;

/*
    Function: findPeakElement
    --------------------------------
    Given an array 'nums', this function finds the index of a "peak element".
    A peak element is one that is strictly greater than its neighbors.

    Approach:
    1. If the array has only one element, that element is trivially a peak (index 0).
    2. If the first element is greater than the second → first element is a peak.
    3. If the last element is greater than the second last → last element is a peak.
    4. Otherwise, use Binary Search between indices 1 and n-2:
        - If nums[mid] is greater than both neighbors → mid is the peak index.
        - If nums[mid] is part of an increasing slope → move search to the right.
        - Else → move search to the left.
    5. If no peak is found in the range (shouldn’t happen with valid input), return -1.
*/
int findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    int st = 1, end = n - 2;

    // Case 1: Only one element in array
    if (n == 1)
        return 0;

    // Case 2: Peak at the start
    if (nums[0] > nums[1])
        return 0;

    // Case 3: Peak at the end
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    // Case 4: Binary search in the middle
    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        // Check if nums[mid] is a peak
        if ((nums[mid - 1] < nums[mid]) && (nums[mid] > nums[mid + 1]))
        {
            return mid;
        }
        // If mid is on an increasing slope, move right
        else if ((nums[mid - 1] < nums[mid]) && (nums[mid] < nums[mid + 1]))
        {
            st = mid + 1;
        }
        // Else, move left
        else
        {
            end = mid - 1;
        }
    }

    return -1; // No peak found (should not happen for valid arrays)
}

/*
    Main function to test the findPeakElement function.
*/
int main()
{
    // Example 1: Single peak in the middle
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Peak index in nums1: " << findPeakElement(nums1) << endl; // Expected: 2

    // Example 2: Peak at the start
    vector<int> nums2 = {5, 3, 2, 1};
    cout << "Peak index in nums2: " << findPeakElement(nums2) << endl; // Expected: 0

    // Example 3: Peak at the end
    vector<int> nums3 = {1, 2, 3, 4};
    cout << "Peak index in nums3: " << findPeakElement(nums3) << endl; // Expected: 3

    // Example 4: Multiple peaks, returns the first one found by binary search
    vector<int> nums4 = {1, 3, 20, 4, 1, 0};
    cout << "Peak index in nums4: " << findPeakElement(nums4) << endl; // Expected: 2

    return 0;
}
