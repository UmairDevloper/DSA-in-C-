#include <bits/stdc++.h>
using namespace std;

/*
Problem: Remove Duplicate Letters

Intuition:
We want the smallest lexicographical string that contains all distinct letters 
from the given string exactly once. To achieve this, we can use a stack 
to maintain the current result while ensuring lexicographical order.

Approach:
1. Use a map to store the last index of every character in the string.
2. Use a stack to maintain characters in order and a set to check visited chars.
3. Traverse the string:
   - If the character is already visited, skip it.
   - Otherwise, while the current character is smaller than the stack top 
     and the stack top will appear again later (using last index), 
     pop it from the stack and mark as unvisited.
   - Push the current character into the stack and mark visited.
4. Finally, build the result string from the stack.

Time Complexity: O(n)  
Space Complexity: O(n)

Example:
Input: "cbacdcbc"
Output: "acdb"
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]] = i;  // store last occurrence
        }

        unordered_set<char> visited;
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            if (visited.find(s[i]) != visited.end()) {
                continue;
            }

            while (!st.empty() && s[i] < st.top() && i < mp[st.top()]) {
                visited.erase(st.top());
                st.pop();
            }
            visited.insert(s[i]);
            st.push(s[i]);
        }

        string res;
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "cbacdcbc";
    cout << "Result: " << sol.removeDuplicateLetters(s) << endl;
    return 0;
}
