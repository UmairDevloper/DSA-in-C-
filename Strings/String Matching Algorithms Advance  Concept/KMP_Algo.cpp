/*
---------------------------------------------
📝 Problem Statement:
Given a text and a pattern, implement the Knuth–Morris–Pratt (KMP) algorithm to find all occurrences of the pattern in the text efficiently.

---------------------------------------------
📖 Example:
Input:
    Text = "ababcababcabc"
    Pattern = "ababc"
Output:
    Pattern found at index 0
    Pattern found at index 5

Explanation:
The KMP algorithm uses the LPS (Longest Prefix Suffix) array to skip unnecessary comparisons, making it faster than the naive approach.

---------------------------------------------
✅ Advantages:
1. Efficient for large texts and patterns.
2. Eliminates redundant comparisons.
3. Time complexity is linear: O(n + m).

❌ Disadvantages:
1. Slightly complex to implement compared to naive approach.
2. Requires preprocessing of the pattern (building the LPS array).

---------------------------------------------
⏱️ Time Complexity:
- Preprocessing (LPS computation): O(m)
- Pattern searching: O(n)
- Overall: O(n + m), where n = length of text, m = length of pattern

💾 Space Complexity:
- O(m) for the LPS array
---------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// Function to build LPS (Longest Prefix Suffix) array
void computeLPSArray(string pattern, vector<int> &lps)
{
    int m = pattern.length();
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Search function
void KMPSearch(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();

    vector<int> lps(m);
    computeLPSArray(pattern, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main()
{
    string text = "ababcababcabc";
    string pattern = "ababc";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl
         << endl;

    KMPSearch(text, pattern);

    return 0;
}
