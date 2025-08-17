// # Valid Anagram

// ## Example
// - Input: `s = "anagram"`, `t = "nagaram"`  
// - Output: `true`

// - Input: `s = "rat"`, `t = "car"`  
// - Output: `false`

// ## Explanation
// We need to check whether two strings are anagrams of each other.  
// - An anagram means both strings contain the **same characters with the same frequency**.  
// - We use an `unordered_map` to count character frequencies in both strings and compare them.  

// ## Solution

// ```cpp

#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, int> sCnt, tCnt;

    for (int i = 0; i < s.length(); i++) {
        sCnt[s[i]]++;
        tCnt[t[i]]++;
    }

    return sCnt == tCnt;
}

int main() {
    string s1 = "anagram", t1 = "nagaram";
    cout << (isAnagram(s1, t1) ? "true" : "false") << endl;

    string s2 = "rat", t2 = "car";
    cout << (isAnagram(s2, t2) ? "true" : "false") << endl;

    return 0;
}
