// # Rotate a Deque

// ```cpp
/*
Problem Statement:
Given a deque of size n and an integer d, rotate the deque by d positions.
Each rotation moves the last element of the deque to the front.
Finally, print the rotated deque.

Approach Used:
- For d times:
  - Take the last element using deq.back().
  - Remove it using deq.pop_back().
  - Insert it at the front using deq.push_front().
- After performing d rotations, print the elements of the deque.

Time Complexity: O(d * n) in worst case (since pushing_front is O(1), but rotation happens d times).
Space Complexity: O(1), as no extra space is used apart from the deque itself.
*/

#include <bits/stdc++.h>
using namespace std;

void rotate(deque<int> deq, int d, int n)
{
    // Perform d rotations
    for (int i = 0; i < d; i++)
    {
        int val = deq.back();
        deq.pop_back();
        deq.push_front(val);
    }

    // Print the rotated deque
    for (int i = 0; i < n; i++)
    {
        cout << deq[i] << " ";
    }
    cout << endl;
}

int main()
{
    deque<int> deq = {1, 2, 3, 4, 5};
    int d = 2;
    int n = deq.size();

    rotate(deq, d, n);
    // Expected Output: 4 5 1 2 3
    return 0;
}
