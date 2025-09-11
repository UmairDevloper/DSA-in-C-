#include <bits/stdc++.h>
using namespace std;

/*
Problem: Largest Rectangle in Histogram

Intuition:
We want to find the largest rectangle that can be formed in a histogram. 
For each bar, we determine the maximum width it can extend left and right 
before hitting a smaller bar.

Approach:
- Use a stack to store indices of increasing bar heights.
- When encountering a smaller height, pop from the stack and calculate 
  the area using the popped height as the limiting bar.
- Repeat until stack is empty or condition satisfies.
- Finally, process remaining bars in the stack.

Time Complexity: O(n)  
Space Complexity: O(n)  

Example:
Input: [2,1,5,6,2,3]
Output: 10
Explanation: The rectangle [5,6] gives max area = 5*2 = 10.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int max_area = 0;

        for(int i = 0; i < heights.size(); i++){
            while(st.top() != -1 && heights[i] <= heights[st.top()]){
                int height = heights[st.top()];
                st.pop();
                int width = i - st.top() - 1;
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }

        while(st.top() != -1){
            int height = heights[st.top()];
            st.pop();
            int width = heights.size() - st.top() - 1;
            max_area = max(max_area, height * width);
        }

        return max_area;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Largest Rectangle Area: " << sol.largestRectangleArea(heights) << endl;
    return 0;
}
