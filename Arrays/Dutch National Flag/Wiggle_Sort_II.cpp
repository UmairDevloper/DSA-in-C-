// Problem: Wiggle Sort
// Given an unsorted array nums, reorder it such that:
// nums[0] < nums[1] > nums[2] < nums[3]...
//
// Example:
// Input: [1, 5, 1, 1, 6, 4]
// Output (one of): [1, 6, 1, 5, 1, 4] or [1, 5, 1, 6, 1, 4]
//
// Approach:
// 1. Sort a copy of the array.
// 2. Use two pointers to fill from the sorted array:
//    - smaller half values go to even indices.
//    - larger half values go to odd indices.
// This ensures wiggle condition: low < high > low < high...

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void wiggleSort(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp(nums);
    sort(temp.begin(), temp.end());

    int l = 0, r = n - 1;
    int mid = (r / 2) + 1;

    while (r >= 0)
    {
        if (r % 2 == 1)
        {
            nums[r] = temp[mid];
            mid++;
        }
        else
        {
            nums[r] = temp[l];
            l++;
        }
        r--;
    }
}

int main()
{
    vector<int> nums = {1, 5, 1, 1, 6, 4};

    cout << "Original Array: ";
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    wiggleSort(nums);

    cout << "Wiggle Sorted Array: ";
    for (int x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}
