#include <bits/stdc++.h>
using namespace std;

/*
Problem: Trapping Rain Water

Intuition:
We need to calculate how much water can be trapped between bars of different heights.  
The amount of water at any index depends on the maximum height to the left and right.  

Approach:
1. Use two pointers (left and right) starting from the edges.  
2. Maintain `lMax` (max height from left so far) and `rMax` (max height from right so far).  
3. If `lMax < rMax`, move left pointer:
   - Update `lMax` and add trapped water = `lMax - height[l]`.  
4. Otherwise, move right pointer:
   - Update `rMax` and add trapped water = `rMax - height[r]`.  
5. Continue until `l >= r`.  

Time Complexity: O(n)  
Space Complexity: O(1)

Example:
Input: [0,1,0,2,1,0,1,3,2,1,2,1]  
Output: 6
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int lMax = height[l];
        int rMax = height[r];
        int water = 0;

        while (l < r) {
            if (lMax < rMax) {
                l++;
                lMax = max(lMax, height[l]);
                water += lMax - height[l];
            } else {
                r--;
                rMax = max(rMax, height[r]);
                water += rMax - height[r];
            }
        }
        return water;
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped Water: " << sol.trap(height) << endl; // Expected: 6
    return 0;
}
