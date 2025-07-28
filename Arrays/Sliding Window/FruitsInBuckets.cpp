// ✅ LeetCode: 904. Fruit Into Baskets
// 🎯 Problem:
// You are given an array `fruits` where `fruits[i]` is the type of fruit at index `i`.
// You can pick at most **two types of fruits** using two baskets.
// Return the length of the longest subarray with at most two distinct integers (fruit types).

// 💡 Approach:
// - Sliding Window technique with a hash map `freq` to count fruit types.
// - Expand the window by moving the `right` pointer.
// - If the window has more than 2 types, shrink it from the `left`.
// - Track the maximum length of valid windows throughout the process.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int left = 0, ans = INT_MIN;
        unordered_map<int, int> freq;

        for (int right = 0; right < fruits.size(); right++)
        {
            freq[fruits[right]]++;

            if (freq.size() <= 2)
                ans = max(ans, right - left + 1);
            else
            {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0)
                    freq.erase(fruits[left]);
                left++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> fruits = {1, 2, 1, 2, 3}; // Example test case
    int result = sol.totalFruit(fruits);

    cout << "Maximum number of fruits in two baskets: " << result << endl;

    return 0;
}
