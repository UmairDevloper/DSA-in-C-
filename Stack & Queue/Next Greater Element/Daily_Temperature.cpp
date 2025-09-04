
// -------------------------------------------------------------------
// 📌 Problem Statement:
// Given an array of integers temp where temp[i] represents the daily 
// temperature on the i-th day, return an array answer such that 
// answer[i] is the number of days you have to wait after the i-th day 
// to get a warmer temperature. If there is no future day for which 
// this is possible, put 0 instead.
//
// -------------------------------------------------------------------
// 🔍 Example:
// Input:  temp = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Explanation:
// - Day 0: 73 → Next warmer day is day 1 (74) → wait 1 day
// - Day 1: 74 → Next warmer day is day 2 (75) → wait 1 day
// - Day 2: 75 → Next warmer day is day 6 (76) → wait 4 days
// - Day 3: 71 → Next warmer day is day 5 (72) → wait 2 days
// - And so on...
//
// -------------------------------------------------------------------
// ⏱️ Time & Space Complexity (Theory):
// Time Complexity: O(n), each temperature index is pushed and popped at most once.
// Space Complexity: O(n), for stack and answer array.
//
// -------------------------------------------------------------------
// ✅ Advantages:
// 1. Efficient O(n) solution using a monotonic decreasing stack.
// 2. Avoids nested loops and brute force O(n^2).
// 3. Easy to extend for similar "next greater element" style problems.
//
// ❌ Disadvantages:
// 1. Requires additional space for stack.
// 2. Logic might be less intuitive for beginners.
//
// -------------------------------------------------------------------
// 🎯 When to Prefer this Solution:
// - For "next warmer day" or "next greater element" type problems.
// - When efficiency is required for large input sizes.
// - Avoid brute force since it will be too slow for long arrays.
// -------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size());
        stack<int> s;

        for (int i = 0; i < temp.size(); i++) {
            // Maintain decreasing stack
            while (!s.empty() && temp[s.top()] < temp[i]) {
                ans[s.top()] = i - s.top(); 
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> temp = {73,74,75,71,69,72,76,73};
    vector<int> result = sol.dailyTemperatures(temp);

    for (int x : result) {
        cout << x << " ";
    }
    // Expected Output: 1 1 4 2 1 1 0 0
    return 0;
}

// -------------------------------------------------------------------
// ⏱️ Time & Space Complexity (for this implementation):
// Time Complexity: O(n)
// Space Complexity: O(n)
// -------------------------------------------------------------------
