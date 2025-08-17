// # Count Palindromic Substrings

// This problem is about counting how many substrings of a given string are **palindromes**.
// A palindrome is a string that reads the same forward and backward (like `aba`, `racecar`, `aa`).

// We use the **expand-around-center** approach:
// - Every palindrome has a center (could be a single character for odd length, or a pair of characters for even length).
// - We expand outward from each possible center as long as the substring is still a palindrome.

// ---

// ## C++ Solution

// ```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int res = 0;

        for (int i = 0; i < s.length(); i++)
        {
            // Odd length palindromes
            res += cnt_palindrome(s, i, i);
            // Even length palindromes
            res += cnt_palindrome(s, i, i + 1);
        }
        return res;
    }

private:
    int cnt_palindrome(string s, int l, int r)
    {
        int cnt = 0;
        while (l >= 0 && r < s.length() && s[l] == s[r])
        {
            cnt++;
            l--;
            r++;
/*************  ✨ Windsurf Command ⭐  *************/
/**
 * Main function to test the solution.
 *
 * @return int the exit status of the program
 *
 * @throws None
 */
/*******  8c2d9899-9118-4f76-894c-0aa6a50312eb  *******/        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    string s = "aaa";
    cout << sol.countSubstrings(s) << endl; // Output: 6
    return 0;
}
