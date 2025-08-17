// # Longest Consecutive Sequence

// ## Example
// - Input: `nums = [100,4,200,1,3,2]`
// - Output: `4`
//   (The longest consecutive sequence is `[1, 2, 3, 4]`)

// - Input: `nums = [0,3,7,2,5,8,4,6,0,1]`
// - Output: `9`
//   (The longest consecutive sequence is `[0,1,2,3,4,5,6,7,8]`)

// ---

// ## Explanation
// - We use an `unordered_set` to store all numbers for **O(1) lookup**.
// - For each number, we check if it is the **start of a sequence** (i.e., `num-1` does not exist).
// - If it is, we count the length of the sequence until numbers stop appearing.
// - Keep track of the maximum length.

// Time Complexity: **O(n)** (each number is visited once).
// Space Complexity: **O(n)** (for the hash set).

// ---

// ## Solution

// ```cpp
#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> numSet(nums.begin(), nums.end());

    int longest = 0;
    for (int num : numSet)
    {
        if (numSet.find(num - 1) == numSet.end())
        { // start of sequence
            int len = 1;
            while (numSet.find(num + len) != numSet.end())
            {
                len++;
            }
            longest = max(longest, len);
        }
    }
    return longest;
}

int main()
{
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums1) << endl; // Output: 4

    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(nums2) << endl; // Output: 9

    return 0;
}
