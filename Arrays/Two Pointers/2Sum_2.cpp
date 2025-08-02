// ✅ Problem: Two Sum II - Input Array Is Sorted (LeetCode #167)
// 🔗 https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// 🧠 Goal: Given a sorted array, return the 1-based indices of two numbers that add up to a target.

// 🔍 Example:
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: 2 + 7 = 9, so return indices (1-based): [1, 2]

#include <iostream>
#include <vector>
using namespace std;

// ✅ Core Logic: Two-pointer approach since array is sorted
vector<int> twoSum(vector<int> &numbers, int target)
{
    int n = numbers.size();
    int i = 0, j = n - 1;

    while (i < j)
    {
        int sum = numbers[i] + numbers[j];

        if (sum == target)
        {
            return {i + 1, j + 1}; // 1-based indexing
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return {-1, -1}; // In case no solution found (though problem guarantees one)
}

// 🧪 Main function for testing
int main()
{
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(numbers, target);

    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
