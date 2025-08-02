// ✅ Problem: Move Zeroes (LeetCode #283)
// 🔗 https://leetcode.com/problems/move-zeroes/
// 🧠 Goal: Move all zeros to the end of the array while maintaining the relative order of the non-zero elements.

// 🔍 Example:
// Input: nums = [0, 1, 0, 3, 12]
// Output: [1, 3, 12, 0, 0]

#include <iostream>
#include <vector>
using namespace std;

// ✅ Core Logic: Two-pointer technique
// i: position for placing the next non-zero element
// j: traverses the array
void moveZeroes(vector<int> &nums)
{
    int i = 0, j = 0;
    int n = nums.size();

    while (j < n)
    {
        if (nums[j] != 0)
        {
            swap(nums[i], nums[j]);
            i++;
        }
        j++;
    }
}

// 🧪 Main function to test the implementation
int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};

    moveZeroes(nums);

    cout << "Output: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
