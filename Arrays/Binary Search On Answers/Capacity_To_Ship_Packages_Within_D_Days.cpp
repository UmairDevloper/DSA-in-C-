#include <bits/stdc++.h>
using namespace std;

/*
    Problem:
    --------
    You are given:
    - weights[]: Array of package weights.
    - days: Number of days to ship all packages.

    You must determine the **minimum ship capacity** that will allow
    all packages to be shipped within the given number of days.

    Rules:
    - Packages must be shipped in order.
    - You cannot split a package.
    - The ship capacity must be at least the maximum single package weight.
    - The ship capacity must be at most the total sum of all package weights.

    Approach:
    ---------
    - Use Binary Search over possible capacities.
    - Low = max weight (minimum possible capacity).
    - High = sum of all weights (maximum possible capacity).
    - For a given mid (capacity), simulate shipping:
        - Keep adding packages until the capacity is exceeded.
        - When exceeded, start a new day and reset current weight.
    - If the required days <= given days → try smaller capacity.
    - Else → increase capacity.
*/

int shipWithinDays(vector<int> &weights, int days)
{
    int maxw = -1, totw = 0;

    // Find the heaviest package and total weight
    for (int w : weights)
    {
        maxw = max(maxw, w);
        totw += w;
    }

    int low = maxw, high = totw;

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Candidate ship capacity
        int currW = 0, requiredDays = 1;

        for (int w : weights)
        {
            // If adding this package exceeds capacity, use another day
            if (currW + w > mid)
            {
                requiredDays++;
                currW = 0;
            }
            currW += w;
        }

        // If within allowed days, try smaller capacity
        if (requiredDays <= days)
        {
            high = mid - 1;
        }
        // Otherwise, need larger capacity
        else
        {
            low = mid + 1;
        }
    }

    return low; // Minimum capacity
}

/*
    Example Runs:
    -------------
    1) weights = [1,2,3,4,5,6,7,8,9,10], days = 5
       Minimum capacity = 15
       Reason: With capacity 15 → ship plan:
       Day 1: 1+2+3+4+5 = 15
       Day 2: 6+7 = 13
       Day 3: 8 = 8
       Day 4: 9 = 9
       Day 5: 10 = 10

    2) weights = [3,2,2,4,1,4], days = 3
       Minimum capacity = 6

    3) weights = [1,2,3,1,1], days = 4
       Minimum capacity = 3
*/

int main()
{
    vector<int> w1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Example 1: " << shipWithinDays(w1, 5) << endl; // Expected: 15

    vector<int> w2 = {3, 2, 2, 4, 1, 4};
    cout << "Example 2: " << shipWithinDays(w2, 3) << endl; // Expected: 6

    vector<int> w3 = {1, 2, 3, 1, 1};
    cout << "Example 3: " << shipWithinDays(w3, 4) << endl; // Expected: 3

    return 0;
}
