// -------------------------------------------------------------------
// 📌 Problem Statement:
// Given a positive integer n, find the smallest integer that has the
// same digits as n and is greater than n.
// If no such integer exists or the result exceeds 32-bit signed int range, return -1.
//
// -------------------------------------------------------------------
// 🔍 Example:
// Input:  n = 1243
// Output: 1324
// Explanation:
// - Digits of n: 1 2 4 3
// - Next lexicographical permutation is: 1 3 2 4
// - Hence, answer = 1324
//
// -------------------------------------------------------------------
// ⏱️ Time & Space Complexity (Theory):
// Time Complexity: O(d), where d is the number of digits in n
// (since next_permutation runs in linear time).
// Space Complexity: O(d), for storing digits in string form.
//
// -------------------------------------------------------------------
// ✅ Advantages:
// 1. Simple and clean implementation using STL `next_permutation`.
// 2. Works efficiently in linear time relative to number of digits.
// 3. Easy to read and maintain.
//
// ❌ Disadvantages:
// 1. Relies on STL — may not be ideal in interviews where manual
//    implementation of next permutation is expected.
// 2. Additional space used for string conversion.
//
// -------------------------------------------------------------------
// 🎯 When to Prefer this Solution:
// - Suitable for competitive programming and real-world coding where
//   STL usage is allowed.
// - Not ideal for interviews that require showing manual logic.
// -------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string str = to_string(n);
        next_permutation(str.begin(), str.end());

        long ans = stol(str);
        return (ans > INT_MAX || ans <= n) ? -1 : ans;
    }
};

int main()
{
    Solution sol;
    int n = 1243;
    cout << sol.nextGreaterElement(n) << endl; // Expected Output: 1324
    return 0;
}

// -------------------------------------------------------------------
// ⏱️ Time & Space Complexity (for this implementation):
// Time Complexity: O(d)
// Space Complexity: O(d)
// -------------------------------------------------------------------
