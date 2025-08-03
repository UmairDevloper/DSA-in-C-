// Problem: Sort Array By Parity
// Given an array nums, move all even integers at the beginning of the array followed by all the odd integers.
// Return any array that satisfies this condition.
// Example:
// Input: [3, 1, 2, 4]
// Output: [4, 2, 1, 3] or any valid rearrangement with evens first

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortArrayByParity(vector<int> &nums)
{
    int l = 0, mid = 0;
    int n = nums.size();
    int r = n - 1;

    while (l < r)
    {
        if (nums[mid] % 2 == 0)
        {
            swap(nums[l], nums[mid]);
            l++;
            mid++;
        }
        else
        {
            swap(nums[mid], nums[r]);
            r--;
        }
    }

    return nums;
}

int main()
{
    vector<int> nums = {3, 1, 2, 4};

    cout << "Original Array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    vector<int> result = sortArrayByParity(nums);

    cout << "Sorted by Parity: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}
