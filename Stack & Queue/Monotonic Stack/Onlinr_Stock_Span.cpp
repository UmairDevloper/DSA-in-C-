#include <bits/stdc++.h>
using namespace std;

/*
Problem: Online Stock Span (LeetCode 901)

Intuition:
-----------
We need to calculate the span of stock prices such that for each price, 
the span is the number of consecutive days (including today) the price 
has been less than or equal to today's price.

A naive approach would check backwards for each price -> O(n^2).
Instead, we use a monotonic decreasing stack storing {price, span}.
- For each new price, pop all prices <= current price and add up their spans.
- Push the new {price, span} to the stack.
- This ensures amortized O(1) per query.

Approach:
----------
1. Maintain a stack of pairs {price, span}.
2. For each incoming price:
   - Start with span = 1.
   - While stack not empty and top price <= current price:
        - Add top span to current span.
        - Pop the top element.
   - Push {price, span} into stack.
   - Return span.

Complexity:
------------
- Time Complexity: Amortized O(1) per query, O(n) for n prices.
- Space Complexity: O(n) for the stack (worst case: strictly decreasing prices).

Example:
----------
Input: [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]
*/

class StockSpanner {
    stack<pair<int, int>> st; // {price, span}
public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    StockSpanner ss;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    cout << "Stock Span Results:\n";
    for (int p : prices) {
        cout << "Price: " << p << " -> Span: " << ss.next(p) << "\n";
    }

    return 0;
}
