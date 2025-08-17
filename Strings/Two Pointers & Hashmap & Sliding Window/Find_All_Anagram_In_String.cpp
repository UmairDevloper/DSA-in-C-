
/*
Example:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
- Substring starting at index 0 ("cba") is an anagram of "abc".
- Substring starting at index 6 ("bac") is an anagram of "abc".
*/

/*
Algorithm Explanation:
1. Count the frequency of each character in string `p`.
2. Use a sliding window of size `k = p.size()` to traverse `s`.
3. For each window:
   - Add the current character into the frequency count.
   - Remove the character that slides out (if window > k).
   - Compare the window frequency with `p`’s frequency.
   - If they match, store the starting index of the window.
4. Return all starting indices of windows that are anagrams.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.size(), k = p.size();
        if (n < k)
            return {};

        vector<int> ans;
        vector<int> freqP(26, 0), freqS(26, 0);

        // Count frequency of chars in p
        for (char c : p)
        {
            freqP[c - 'a']++;
        }

        // Sliding window over s
        for (int i = 0; i < n; i++)
        {
            // Add current char into window
            freqS[s[i] - 'a']++;

            // Remove char that's sliding out of window
            if (i >= k)
            {
                freqS[s[i - k] - 'a']--;
            }

            // If window size = k and frequency matches, record index
            if (freqS == freqP)
            {
                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};

// End-to-End Example Test:
int main()
{
    Solution sol;
    string s = "cbaebabacd", p = "abc";
    vector<int> result = sol.findAnagrams(s, p);

    for (int idx : result)
    {
        cout << idx << " ";
    }
    // Expected Output: 0 6
    return 0;
}

/*
Time Complexity:
- O(n) where n = length of string `s`
  (since each character is processed once in the sliding window).
- Frequency comparison is O(26) = O(1).

Space Complexity:
- O(26) = O(1) for frequency arrays.
- O(k) for the result storage.
*/
