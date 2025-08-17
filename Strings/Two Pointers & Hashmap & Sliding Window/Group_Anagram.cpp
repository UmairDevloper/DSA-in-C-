// # Group Anagrams

// ```cpp
/*
Example:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["eat","tea","ate"],["tan","nat"],["bat"]]

Explanation:
- The words "eat", "tea", and "ate" are anagrams (they can be rearranged to form each other).
- The words "tan" and "nat" are anagrams.
- "bat" has no other anagram partner.
Hence the grouping is [["eat","tea","ate"],["tan","nat"],["bat"]].

Algorithm Explanation:
1. Create a hashmap where the key is the sorted version of a string, and the value is a list of words that match that sorted key.
2. For each string in the input list:
   - Sort the string.
   - Use the sorted string as the key and push the original string into the hashmap.
3. At the end, collect all values (groups of anagrams) from the hashmap and return them.

This works because all anagrams will share the same sorted string.
*/

#include <bits/stdc++.h>
using namespace std;
// ✅ Solution
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> ans;

    for (string &s : strs)
    {
        string key = s;
        sort(key.begin(), key.end());
        ans[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto &entry : ans)
    {
        result.push_back(entry.second);
    }

    return result;
}

// ✅ End-to-End Part (Driver Code Example)
int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);

    // Print result
    for (auto &group : result)
    {
        cout << "[ ";
        for (auto &word : group)
        {
            cout << word << " ";
        }
        cout << "] ";
    }
    return 0;
}

/*
Time Complexity:
- Sorting each string takes O(k log k), where k = average length of strings.
- For n strings, total = O(n * k log k).

Space Complexity:
- Hashmap stores all strings, requiring O(n * k) space.
*/