/*
Problem Statement:
Implement the `strStr()` function that finds the first occurrence of a substring (needle) in a string (haystack).
If the substring is not found, return -1.
You must solve it efficiently without using built-in string search functions.

Example:
Input: haystack = "hello", needle = "ll"
Output: 2

Explanation:
The substring "ll" is found in "hello" starting at index 2.

Approach:
We use the **Rabin-Karp algorithm** (string hashing) to efficiently check substring matches.
Instead of checking each substring directly (O(n*m)), we calculate hash values for the substring and sliding windows in the haystack.
If hashes match, we do a character-by-character comparison to confirm.

*/

// Function implementing Rabin-Karp algorithm

#include <bits/stdc++.h>
using namespace std;

int strStr(string haystack, string needle)
{
    int n = haystack.size();
    int m = needle.size();
    if (m > n)
        return -1; // no match possible

    const int d = 256; // number of characters in input alphabet
    const int q = 101; // a prime number (modulus)

    int h = 1; // d^(m-1) % q
    for (int i = 0; i < m - 1; i++)
    {
        h = (h * d) % q;
    }

    int p = 0; // hash value for pattern
    int t = 0; // hash value for current text window

    // Initial hash for pattern and first window
    for (int i = 0; i < m; i++)
    {
        p = (d * p + needle[i]) % q;
        t = (d * t + haystack[i]) % q;
    }

    // Slide the pattern over text
    for (int i = 0; i <= n - m; i++)
    {
        // If hashes match, check characters one by one
        if (p == t)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
                return i; // return first index of match
        }

        // Recalculate hash for next window
        if (i < n - m)
        {
            t = (d * (t - haystack[i] * h) + haystack[i + m]) % q;
            if (t < 0)
                t += q; // make sure hash is positive
        }
    }

    return -1; // not found
}

int main()
{
    string haystack = "hello";
    string needle = "ll";

    int result = strStr(haystack, needle);
    cout << "First occurrence index: " << result << endl;

    return 0;
}

/*
Time Complexity:
- Preprocessing hash: O(m)
- Sliding window comparisons: O(n - m + 1)
- Worst case (when hash collisions occur): O(n*m)
- Average case: O(n + m)

Space Complexity: O(1)
- Only extra variables for hash and counters are used.
*/
