#include <bits/stdc++.h>
using namespace std;

/*
Example:
Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"

Explanation:
We take one character alternately from each string:
- Take 'a' from word1, 'p' from word2 → "ap"
- Take 'b' from word1, 'q' from word2 → "apbq"
- Take 'c' from word1, 'r' from word2 → "apbqc r"
Final result = "apbqcr"

Algorithm Explanation:
1. Initialize an empty result string `ans`.
2. Use a pointer `i` to iterate through both words simultaneously.
3. If `i` is within bounds of `word1`, add `word1[i]`.
4. If `i` is within bounds of `word2`, add `word2[i]`.
5. Keep increasing `i` until both words are fully traversed.
6. Return the merged string.
*/

// Solution
string mergeAlternately(string word1, string word2)
{
    string ans = "";
    int i = 0;
    while (i < word1.length() || i < word2.length())
    {
        if (i < word1.length())
        {
            ans += word1[i];
        }
        if (i < word2.length())
        {
            ans += word2[i];
        }
        i++;
    }
    return ans;
}

// End-to-End
int main()
{
    string word1 = "abc", word2 = "pqr";
    cout << mergeAlternately(word1, word2) << endl; // Output: apbqcr
    return 0;
}

/*
Time Complexity: O(max(n, m)), where n = length of word1 and m = length of word2
Space Complexity: O(n + m) for storing the result string
*/
