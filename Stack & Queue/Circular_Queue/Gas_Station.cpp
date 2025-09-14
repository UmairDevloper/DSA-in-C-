// #Gas Station Problem

// ```cpp
/*
Problem Statement:
There are n gas stations arranged in a circular route, where gas[i] is the amount of gas at station i
and cost[i] is the cost of gas required to travel from station i to (i+1).
Find the starting gas station index if you can travel around the circuit once, otherwise return -1.

Approach Used:
- Track total gas and total cost.
- Keep a running fuel balance while iterating.
- If fuel becomes negative at station i, reset the starting point to i+1.
- After traversal, if total gas < total cost, return -1. Otherwise, return the starting index.

Time Complexity: O(n)  -> Single traversal of arrays.
Space Complexity: O(1) -> Only a few variables are used.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int st = 0, fuel = 0;
        int totg = 0, totc = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            fuel += gas[i] - cost[i];
            totg += gas[i];
            totc += cost[i];

            if (fuel < 0)
            {
                st = i + 1;
                fuel = 0;
            }
        }

        return (totg < totc) ? -1 : st;
    }
};

int main()
{
    Solution sol;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    cout << sol.canCompleteCircuit(gas, cost) << endl;
    // Expected Output: 3
    return 0;
}
