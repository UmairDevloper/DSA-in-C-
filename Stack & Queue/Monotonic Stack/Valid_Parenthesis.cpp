#include <bits/stdc++.h>
using namespace std;

/*
Problem: Valid Parentheses
---------------------------------
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

A string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

---------------------------------
Intuition:
We need to check whether every opening bracket has a matching closing bracket
and that they close in the right order. A stack is the perfect data structure
for this because it follows LIFO (Last In, First Out) principle, just like 
brackets need to be matched.

---------------------------------
Approach:
1. Traverse the string character by character.
2. If we encounter an opening bracket '(', '{', '[', push it into the stack.
3. If we encounter a closing bracket ')', '}', ']', check:
   - If the stack is empty → invalid string.
   - If the top of the stack is not the matching opening bracket → invalid string.
   - Otherwise, pop the stack.
4. At the end, if the stack is empty → valid string, otherwise invalid.

---------------------------------
Time Complexity: O(n)  
- We iterate through the string once.

Space Complexity: O(n)  
- In the worst case, all characters are opening brackets stored in the stack.

---------------------------------
Example:
Input: s = "()[]{}"
Output: true

Input: s = "(]"
Output: false
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> v;
        for (char &c : s) {
            if (c == '(' || c == '{' || c == '[') {
                v.push(c);
            } else {
                if (v.empty()) return false;
                if ((c == ')' && v.top() != '(') || 
                    (c == ']' && v.top() != '[') ||
                    (c == '}' && v.top() != '{')) 
                    return false;
                v.pop();
            }
        }
        return v.empty();
    }
};

int main() {
    Solution sol;
    string s1 = "()[]{}";
    string s2 = "(]";
    string s3 = "({[]})";

    cout << boolalpha;  // print true/false instead of 1/0
    cout << "s1: " << sol.isValid(s1) << endl; // true
    cout << "s2: " << sol.isValid(s2) << endl; // false
    cout << "s3: " << sol.isValid(s3) << endl; // true

    return 0;
}
