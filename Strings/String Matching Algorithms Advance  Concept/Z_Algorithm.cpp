/*
------------------------------------------------------
    Algorithm: Z Algorithm (String Matching)
    File: zAlgorithmStringMatching.cpp
    Author: [Your Name]
------------------------------------------------------

📌 Problem Statement:
Given a text and a pattern, implement the Z Algorithm
to find all occurrences of the pattern in the text in
O(n + m) time, where:
    - n = length of the text
    - m = length of the pattern

Example:
---------
Text    = "aabxaabxcaabxaabxay"
Pattern = "aabx"

Output:
Pattern found at indices: 0 4 8

------------------------------------------------------

📖 Theory / Approach:
The Z Algorithm is a linear-time string matching algorithm.
It works by creating a Z-array for a string. The Z-array
represents the length of the longest substring starting at
position i that matches the prefix of the string.

Steps:
1. Concatenate pattern + '$' + text, where '$' is a delimiter
   that does not appear in either string.
2. Compute the Z-array for the concatenated string.
3. Whenever Z[i] equals the pattern length, a match is found.
4. Report the starting index in the text.

------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// Function to compute the Z-array
vector<int> computeZ(string s)
{
    int n = s.size();
    vector<int> Z(n, 0);

    int L = 0, R = 0; // window [L, R] where substring matches prefix
    for (int i = 1; i < n; i++)
    {
        if (i <= R)
        {
            Z[i] = min(R - i + 1, Z[i - L]);
        }
        // Try to extend the match as far as possible
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
        {
            Z[i]++;
        }
        // Update [L, R] if extended past R
        if (i + Z[i] - 1 > R)
        {
            L = i;
            R = i + Z[i] - 1;
        }
    }
    return Z;
}

// Z Algorithm implementation for pattern searching
void zAlgorithmStringMatching(string text, string pattern)
{
    // Concatenate pattern + "$" + text
    string concat = pattern + "$" + text;
    vector<int> Z = computeZ(concat);

    int m = pattern.size();
    cout << "Pattern found at indices: ";
    for (int i = 0; i < Z.size(); i++)
    {
        if (Z[i] == m)
        {
            // Pattern found starting at index (i - m - 1) in text
            cout << (i - m - 1) << " ";
        }
    }
    cout << endl;
}

// Main function to test the algorithm
int main()
{
    string text = "aabxaabxcaabxaabxay";
    string pattern = "aabx";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    zAlgorithmStringMatching(text, pattern);

    return 0;
}

/*
------------------------------------------------------
⏱️ Time Complexity:
- Building Z-array: O(n + m)
- Pattern searching: O(n + m)
Overall: O(n + m)

💾 Space Complexity:
- Z-array of size (n + m + 1) → O(n + m)

------------------------------------------------------
*/
