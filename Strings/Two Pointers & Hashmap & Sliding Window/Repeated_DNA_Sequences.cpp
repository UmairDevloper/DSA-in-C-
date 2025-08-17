/*
Example Statement:
------------------
Given a string `s` that represents a DNA sequence, return all the 10-letter-long sequences
(substrings) that occur more than once in the DNA molecule.

Example:
--------
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

Explanation:
------------
- "AAAAACCCCC" appears multiple times.
- "CCCCCAAAAA" also appears multiple times.
- We only return unique sequences that occur more than once.

-------------------------------------------------------

Algorithm Explanation:
----------------------
1. Iterate through the string with a sliding window of length 10.
2. Extract each substring of length 10 and store it in a hash map (unordered_map).
   - Key = substring of length 10
   - Value = count of occurrences
3. After processing, collect all substrings whose count > 1 into a result vector.
4. Return the result.

-------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    int n = s.size();
    unordered_map<string, int> mp;

    // Store frequency of every 10-letter substring
    for (int i = 0; i <= n - 10; i++)
    {
        mp[s.substr(i, 10)]++;
    }

    vector<string> ans;
    // Collect only substrings that appear more than once
    for (auto &ele : mp)
    {
        if (ele.second > 1)
        {
            ans.push_back(ele.first);
        }
    }
    return ans;
}

int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result = findRepeatedDnaSequences(s);

    cout << "Repeated DNA Sequences: ";
    for (auto &seq : result)
    {
        cout << seq << " ";
    }
    cout << endl;

    return 0;
}

/*
-------------------------------------------------------

Space & Time Complexity:
------------------------
- Time Complexity: O(N * L)
  where N = length of string, L = 10 (substring extraction & hashing).
  Since L = 10 (constant), effectively O(N).

- Space Complexity: O(N)
  for storing substrings in the hash map and result vector.

-------------------------------------------------------
*/
