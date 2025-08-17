#include <bits/stdc++.h>
using namespace std;

/*
Example:
Input: chars = ['a','a','b','b','c','c','c']
Output: 6
Explanation:
The compressed array is ['a','2','b','2','c','3'].
The length returned is 6, meaning only the first 6 characters are valid.

---

Algorithm Explanation:
1. Initialize an index pointer `idx = 0` to keep track of position for compressed array.
2. Traverse the array with a pointer `r`.
3. For each character, count its consecutive occurrences (`len`).
4. If count == 1 → just place the character.
   If count > 1 → place character + digits of count.
5. Resize the array to the new compressed length.
6. Return the compressed length.

---

Time Complexity:
O(n) → Each character is processed once.
Space Complexity:
O(1) → Constant extra space.
*/

int compress(vector<char> &chars)
{
    int idx = 0;
    int n = chars.size();
    for (int r = 0; r < n; r++)
    {
        int len = 0;
        char ch = chars[r];
        while (r < n && chars[r] == ch)
        {
            len++;
            r++;
        }
        if (len == 1)
        {
            chars[idx++] = ch;
        }
        else
        {
            chars[idx++] = ch;
            string str = to_string(len);
            for (char dig : str)
            {
                chars[idx++] = dig;
            }
        }
        r--; // adjust because for-loop increments r
    }
    chars.resize(idx);
    return idx;
}

// --- End-to-End Code ---
int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength = compress(chars);

    cout << "Compressed Length: " << newLength << endl;
    cout << "Compressed Array: ";
    for (int i = 0; i < newLength; i++)
    {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}
