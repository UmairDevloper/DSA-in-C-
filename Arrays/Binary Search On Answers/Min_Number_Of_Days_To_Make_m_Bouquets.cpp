#include <bits/stdc++.h>
using namespace std;

/*
    Problem:
    --------
    You are given:
    - bloomDay[]: An array where bloomDay[i] = the day on which the i-th flower will bloom.
    - m: Number of bouquets you need to make.
    - k: Number of adjacent flowers needed for one bouquet.

    You need to find the minimum day on which you can make at least 'm' bouquets.
    If it's not possible, return -1.

    Approach:
    ---------
    - We use Binary Search over the "days".
    - For each mid (candidate day), we check if we can make >= m bouquets using flowers that have bloomed by day 'mid'.
    - If possible, try to find a smaller day (move left).
    - Else, move right to find a later day.
*/

/*
    Helper function:
    ----------------
    getNumOfBouquets(bloomDay, mid, k)
    - Counts how many bouquets can be made if we wait until 'mid' days.
    - Flowers that bloom on or before 'mid' can be used.
    - A bouquet requires 'k' adjacent bloomed flowers.
*/
int getNumOfBouquets(vector<int> &bloomDay, int mid, int k)
{
    int numOfBouquets = 0;
    int count = 0; // Count of consecutive bloomed flowers

    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= mid)
        {
            count++;
        }
        else
        {
            count = 0; // Reset if flower not bloomed
        }

        if (count == k)
        {
            numOfBouquets++;
            count = 0; // Reset after making one bouquet
        }
    }
    return numOfBouquets;
}

/*
    Main function:
    --------------
    minDays(bloomDay, m, k)
    - Uses binary search over possible days to find the minimum day
      on which m bouquets can be made.
*/
int minDays(vector<int> &bloomDay, int m, int k)
{
    long long totalFlowersNeeded = (long long)m * k;
    if (totalFlowersNeeded > bloomDay.size())
        return -1; // Not enough flowers

    int start = 0;
    int end = *max_element(bloomDay.begin(), bloomDay.end()); // Max day

    int minDaysResult = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (getNumOfBouquets(bloomDay, mid, k) >= m)
        {
            minDaysResult = mid; // Possible answer
            end = mid - 1;       // Try smaller day
        }
        else
        {
            start = mid + 1; // Need more days
        }
    }

    return minDaysResult;
}

/*
    Test the code with multiple scenarios
*/
int main()
{
    // Example 1:
    // bloomDay = [1, 10, 3, 10, 2], m = 3, k = 1
    // We need 3 bouquets, each with 1 flower.
    // Minimum day = 3 (flowers at days 1, 2, and 3 will have bloomed)
    vector<int> bloom1 = {1, 10, 3, 10, 2};
    cout << "Minimum days (Example 1): " << minDays(bloom1, 3, 1) << endl; // Expected: 3

    // Example 2:
    // bloomDay = [1, 10, 3, 10, 2], m = 3, k = 2
    // We need 3 bouquets, each with 2 adjacent flowers.
    // Not possible because we need 6 flowers in total, but only 5 available.
    vector<int> bloom2 = {1, 10, 3, 10, 2};
    cout << "Minimum days (Example 2): " << minDays(bloom2, 3, 2) << endl; // Expected: -1

    // Example 3:
    // bloomDay = [7, 7, 7, 7, 12, 7, 7]
    // m = 2, k = 3
    // Possible by day 12.
    vector<int> bloom3 = {7, 7, 7, 7, 12, 7, 7};
    cout << "Minimum days (Example 3): " << minDays(bloom3, 2, 3) << endl; // Expected: 12

    return 0;
}
