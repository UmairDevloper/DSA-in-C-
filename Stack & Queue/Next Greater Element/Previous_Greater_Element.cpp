
// -------------------------------------------------------------------
// 📌 Problem Statement:
// Given an array arr[], the task is to find the Previous Greater Element (PGE) 
// for every element in the array. 
// The Previous Greater Element of an element arr[i] is the closest element to 
// the left of arr[i] that is greater than arr[i]. 
// If no such element exists, store -1.
//
// -------------------------------------------------------------------
// 🔍 Example:
// Input:  arr = [10, 4, 2, 20, 40, 12, 30]
// Output: [-1, 10, 4, -1, -1, 40, 40]
// Explanation:
// - For arr[0] = 10 → no previous element → -1
// - For arr[1] = 4 → previous greater is 10
// - For arr[2] = 2 → previous greater is 4
// - For arr[3] = 20 → no previous greater → -1
// - For arr[4] = 40 → no previous greater → -1
// - For arr[5] = 12 → previous greater is 40
// - For arr[6] = 30 → previous greater is 40
//
// -------------------------------------------------------------------
// ⏱️ Time & Space Complexity (Theory):
// Time Complexity: O(n), each element is pushed and popped at most once.
// Space Complexity: O(n), for stack and result array.
//
// -------------------------------------------------------------------
// ✅ Advantages:
// 1. Efficient O(n) solution using monotonic stack.
// 2. Much faster than brute force O(n^2).
// 3. Can be easily adapted for Next Greater/Smaller variants.
//
// ❌ Disadvantages:
// 1. Requires extra space for stack.
// 2. Slightly harder to understand than brute force for beginners.
//
// -------------------------------------------------------------------
// 🎯 When to Prefer this Solution:
// - When solving "Previous Greater Element" problems in competitive programming.
// - Large input size where brute force would be inefficient.
// - As a building block for stock span, histogram, and similar problems.
// -------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> preGreaterEle(vector<int>& arr) {
        int n = arr.size();
        // initialize all PGEs as -1
        vector<int> result(n, -1); 
        stack<int> s; 

        // traverse the array from left to right
        for (int i = 0; i < n; i++) {
            // pop elements from stack which are <= current element
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();
            }

            // if stack is not empty, top element is PGE
            if (!s.empty()) {
                result[i] = s.top();
            }

            // push current element onto stack
            s.push(arr[i]);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {10, 4, 2, 20, 40, 12, 30};
    vector<int> result = sol.preGreaterEle(arr);

    for (int x : result) {
        cout << x << " ";
    }
    // Expected Output: -1 10 4 -1 -1 40 40
    return 0;
}

// -------------------------------------------------------------------
// ⏱️ Time & Space Complexity (for this implementation):
// Time Complexity: O(n)
// Space Complexity: O(n)
// -------------------------------------------------------------------
