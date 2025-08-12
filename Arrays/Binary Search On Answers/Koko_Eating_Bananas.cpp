#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Koko Eating Bananas
    ----------------------------
    Koko loves bananas. There are N piles of bananas, where piles[i] is the number
    of bananas in the i-th pile. She wants to eat all the bananas in H hours.

    Each hour, she chooses one pile and eats at most K bananas from it.
    If the pile has less than K bananas, she eats all of them and doesn't continue
    with another pile in that same hour.

    Task:
    -----
    Find the **minimum integer eating speed K** (bananas/hour) such that she can
    eat all the bananas within H hours.

    Approach (Binary Search on Answer):
    ------------------------------------
    1. Minimum eating speed = 1 banana/hour (slowest possible).
    2. Maximum eating speed = max pile size (fastest possible).
    3. Use Binary Search to find the smallest K that satisfies the condition:
        - Calculate total hours needed at speed mid:
            hours += ceil(pile_size / mid)
        - If hours <= H → possible, try smaller K.
        - Else → increase K.
*/

int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());

    while (low < high)
    {
        int mid = (low + high) / 2;

        long long total = 0; // total hours needed at speed mid
        for (int val : piles)
        {
            // Equivalent to ceil(val / mid) without floating point
            total += (val + mid - 1) / mid;
        }

        if (total <= h)
        {
            // Can finish in time, try smaller speed
            high = mid;
        }
        else
        {
            // Too slow, increase speed
            low = mid + 1;
        }
    }

    return low; // Minimum speed
}

/*
    Example Runs:
    -------------
    1) piles = [3,6,7,11], h = 8
       Minimum speed = 4 bananas/hour
       Reason: With speed 4 → hours:
       pile=3 → 1 hr, pile=6 → 2 hrs, pile=7 → 2 hrs, pile=11 → 3 hrs → total=8 hrs

    2) piles = [30,11,23,4,20], h = 5
       Minimum speed = 30

    3) piles = [30,11,23,4,20], h = 6
       Minimum speed = 23
*/

int main()
{
    vector<int> piles1 = {3, 6, 7, 11};
    cout << "Example 1: " << minEatingSpeed(piles1, 8) << endl; // Expected: 4

    vector<int> piles2 = {30, 11, 23, 4, 20};
    cout << "Example 2: " << minEatingSpeed(piles2, 5) << endl; // Expected: 30

    vector<int> piles3 = {30, 11, 23, 4, 20};
    cout << "Example 3: " << minEatingSpeed(piles3, 6) << endl; // Expected: 23

    return 0;
}
