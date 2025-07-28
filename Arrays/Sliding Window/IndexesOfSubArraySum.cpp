// ✅ Problem: Subarray with Given Sum
// 🎯 Given an array of integers `arr` and an integer `target`,
// find a continuous subarray that adds up to `target` and return
// its starting and ending (1-based) indices. If no such subarray exists, return {-1}.

// 💡 Approach (Sliding Window):
// - Use two pointers `i` (start) and `j` (end) to define the window.
// - Expand the window by adding `arr[j]`.
// - Shrink the window from left while `sum > target`.
// - If `sum == target`, return 1-based indices.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        int i = 0, j = 0, sum = 0, n = arr.size();

        while (j < n)
        {
            sum += arr[j];

            while (sum > target)
            {
                sum -= arr[i];
                i++;
            }

            if (sum == target)
            {
                return {i + 1, j + 1}; // 1-based indexing
            }

            j++;
        }

        return {-1}; // No valid subarray found
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {1, 2, 3, 7, 5};
    int target = 12;

    vector<int> result = sol.subarraySum(arr, target);
    if (result.size() == 1 && result[0] == -1)
    {
        cout << "No subarray found with the given sum." << endl;
    }
    else
    {
        cout << "Subarray found from index " << result[0] << " to " << result[1] << endl;
    }

    return 0;
}
