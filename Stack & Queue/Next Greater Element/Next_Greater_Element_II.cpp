
// -------------------------------------------------------------------
// 📌 Problem Statement:
// Given a circular integer array nums (the next element of the last
// element is the first element of the array), return the next greater
// number for every element in nums.
// If it doesn’t exist, return -1 for that number.
//
// The next greater number of a number x is the first greater number
// to its traversing-order next in the array, which means you may
// search circularly to find its next greater number.
// -------------------------------------------------------------------
//
// 🔍 Example:
// Input:  nums = [1, 2, 1]
// Output: [2, -1, 2]
// Explanation:
// - For nums[0] = 1 → next greater is 2
// - For nums[1] = 2 → no greater element, answer = -1
// - For nums[2] = 1 → next greater is 2 (circularly)
//
// -------------------------------------------------------------------
// ⏱️ Time & Space Complexity (Theory):
// Time Complexity: O(n), each element is pushed and popped at most once.
// Space Complexity: O(n), for stack and output array.
//
// -------------------------------------------------------------------
// ✅ Advantages:
// 1. Efficient O(n) solution using monotonic stack.
// 2. Works well for circular arrays by simulating twice traversal.
// 3. Optimized compared to brute force O(n^2).
//
// ❌ Disadvantages:
// 1. Slightly harder to understand for beginners due to stack logic.
// 2. Extra space used for stack.
//
// -------------------------------------------------------------------
// 🎯 When to Prefer this Solution:
// - When asked for Next Greater Element in circular arrays.
// - When efficiency is required (linear time).
// - Avoid brute force approach as it will be too slow for large n.
// -------------------------------------------------------------------

#include <bits/stdc++.h>
    using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);

        // Push indices for circular handling
        for (int i = n - 1; i >= 0; i--)
        {
            st.push(i);
        }

        // Traverse again and maintain next greater elements
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
            {
                st.pop();
            }
            if (!st.empty() && nums[st.top()] > nums[i])
            {
                ans[i] = nums[st.top()];
            }
            st.push(i);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> result = sol.nextGreaterElements(nums);

    for (int x : result)
    {
        cout << x << " ";
    }
    // Expected Output: 2 -1 2
    return 0;
}

// -------------------------------------------------------------------
// ⏱️ Time & Space Complexity (for this implementation):
// Time Complexity: O(n)
// Space Complexity: O(n)
// -------------------------------------------------------------------
