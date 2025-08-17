#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int left = 0;
        int maxLength = 0;
        unordered_set<char> charSet;

        for (int right = 0; right < s.length(); right++)
        {
            // If the current character already exists in the set,
            // move the left pointer until the duplicate is removed.
            while (charSet.find(s[right]) != charSet.end())
            {
                charSet.erase(s[left]);
                left++;
            }

            // Insert the current character and update max length.
            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main()
{
    Solution solution;

    // Example 1
    string s1 = "abcabcbb";
    cout << "Input: " << s1 << endl;
    cout << "Output (Longest Substring Length): "
         << solution.lengthOfLongestSubstring(s1) << endl;
    cout << "-----------------------------" << endl;

    // Example 2
    string s2 = "bbbbb";
    cout << "Input: " << s2 << endl;
    cout << "Output (Longest Substring Length): "
         << solution.lengthOfLongestSubstring(s2) << endl;
    cout << "-----------------------------" << endl;

    // Example 3
    string s3 = "pwwkew";
    cout << "Input: " << s3 << endl;
    cout << "Output (Longest Substring Length): "
         << solution.lengthOfLongestSubstring(s3) << endl;

    return 0;
}

// ✅ What this does

// Includes your function inside a Solution class (just like LeetCode).

// Adds a main function with three test cases:

// "abcabcbb" → Output: 3 ("abc")

// "bbbbb" → Output: 1 ("b")

// "pwwkew" → Output: 3 ("wke")