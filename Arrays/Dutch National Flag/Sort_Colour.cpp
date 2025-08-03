// Problem: Sort Colors (LeetCode 75)
// Given an array with n objects colored red (0), white (1), or blue (2),
// sort them in-place so that objects of the same color are adjacent in the order 0, 1, 2.
// Example:
// Input: [2, 0, 2, 1, 1, 0]
// Output: [0, 0, 1, 1, 2, 2]

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;

    // Dutch National Flag Algorithm
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Original Array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    sortColors(nums);

    cout << "Sorted Colors: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
