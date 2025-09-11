# Problem: Remove K Digits

---

## Intuition
We need to remove `k` digits from the given number string `num` such that the resulting number is the **smallest possible**.  
A digit that is larger and sits before a smaller digit should be removed (if possible), because removing it yields a smaller number.  
This suggests a greedy, monotonic-increasing "stack" approach (we use a string as the stack).

---

## Approach
1. Use a string `s` as a stack to build the resulting number.
2. Traverse each character `a` in `num`:
   - While `s` is not empty, `k > 0`, and `s.back() > a`:
     - Pop the last character from `s` and decrement `k`.
   - Push `a` into `s`.
3. If `k > 0` after the loop, remove the last `k` characters from `s`.
4. Strip leading zeros from `s`.
5. If `s` becomes empty, return `"0"`, otherwise return `s`.

---

## Complexity
- **Time Complexity:** `O(n)` — each digit is pushed and popped at most once.  
- **Space Complexity:** `O(n)` — extra string `s` in worst case.

---

## Example
Input: `num = "1432219", k = 3`  
Process greedily removing larger digits before smaller ones → result = `"1219"`

---

## Code (C++)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string s = "";
        for (char a : num) {
            while (!s.empty() && k > 0 && s.back() > a) {
                s.pop_back();
                k--;
            }
            s.push_back(a);
        }

        // If k still remains, remove from the end safely
        if (k > 0) {
            if (k >= (int)s.size()) s = "";
            else s = s.substr(0, s.size() - k);
        }

        // Remove leading zeros
        int i = 0;
        while (i < (int)s.size() && s[i] == '0') i++;
        s = (i == (int)s.size()) ? "0" : s.substr(i);
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // Sample test 1
    string num1 = "1432219";
    int k1 = 3;
    cout << "Input: num = \"" << num1 << "\", k = " << k1 << "\n";
    cout << "Output: \"" << sol.removeKdigits(num1, k1) << "\"\n\n";

    // Sample test 2
    string num2 = "10200";
    int k2 = 1;
    cout << "Input: num = \"" << num2 << "\", k = " << k2 << "\n";
    cout << "Output: \"" << sol.removeKdigits(num2, k2) << "\"\n\n";

    // You can also read custom input from stdin:
    // string num; int k;
    // if (cin >> num >> k) {
    //     cout << sol.removeKdigits(num, k) << "\n";
    // }

    return 0;
}
```
