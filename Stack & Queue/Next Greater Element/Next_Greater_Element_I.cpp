
// -------------------------------------------------------------------
// 📌 Problem Statement:
// The Next Greater Element of some element x in an array is the first 
// greater element that is to the right of x in the same array.
//
// You are given two distinct integer arrays nums1 and nums2, where nums1 
// is a subset of nums2. For each element in nums1, find the next greater 
// element in nums2. If it does not exist, return -1 for that number.
//
// -------------------------------------------------------------------
// 🔍 Example:
// Input:  
// nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: 
// - For 4 → no greater element to the right → -1
// - For 1 → next greater element is 3
// - For 2 → no greater element to the right → -1
//
// Input:  
// nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// -------------------------------------------------------------------
//
// ⏱️ Time & Space Complexity (Theory):
// Time Complexity: O(n + m), where n = nums1.size(), m = nums2.size().
// - Each element in nums2 is processed once in the monotonic stack.
// - Lookup in hashmap is O(1) for each nums1 element.
// Space Complexity: O(m), for hashmap + stack.
//
// -------------------------------------------------------------------
// ✅ Advantages:
// 1. Efficient O(n + m) solution using monotonic decreasing stack.
// 2. Avoids brute force O(n*m) scanning.
// 3. Uses hash map for O(1) lookups.
//
// ❌ Disadvantages:
// 1. Requires extra space for stack and hashmap.
// 2. Slightly more complex to understand at first compared to brute force.
//
// -------------------------------------------------------------------
// 🎯 When to Prefer this Solution:
// - When given nums1 as a subset of nums2.
// - Need efficient solution for large arrays.
// - Avoid brute force approaches due to time limits.
// -------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nxt;
        stack<int> st;

        // Build map for next greater elements in nums2
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            nxt[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        // Prepare result for nums1 based on map
        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(nxt[x]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    for (int x : result) {
        cout << x << " ";
    }
    // Expected Output: -1 3 -1
    return 0;
}

// -------------------------------------------------------------------
// ⏱️ Time & Space Complexity (for this implementation):
// Time Complexity: O(n + m)
// Space Complexity: O(m)
// -------------------------------------------------------------------
