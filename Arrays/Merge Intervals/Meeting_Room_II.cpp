// 🧠 Problem Statement: Minimum Number of Meeting Rooms
// You're given two arrays:

// start[]: Start times of meetings

// end[]: End times of meetings

// Each index i represents a meeting that starts at start[i] and ends at end[i].

// Goal:
// Find the minimum number of meeting rooms required so that all the meetings can be scheduled without any overlap.

// 💡 Intuition & Explanation
// This is a classic interval overlap problem.

// To avoid conflicts:

// We want to count how many meetings overlap at any given time.

// The maximum number of overlaps will be the number of rooms needed.

// ✅ Optimized Approach
// Sort both the start[] and end[] arrays.

// Use two pointers:

// i for traversing start times

// j for traversing end times

// For each start[i]:

// If start[i] < end[j], it means we need a new room.

// Else, we can reuse a room because a previous meeting has ended.

// Keep track of:

// k: number of meetings started so far.

// i: number of meetings ended so far.

// k - i: gives number of active meetings, i.e., rooms needed at that point.

// Return the maximum number of active meetings as the result.

// 🧾 Code (with main function)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find minimum number of meeting rooms
int minMeetingRooms(vector<int> &start, vector<int> &end)
{
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int k = 0, ans = 0;
    int n = end.size();

    for (int i = 0; i < n; i++)
    {
        while (k < start.size() && start[k] < end[i])
        {
            k++;
        }
        ans = max(ans, k - i);
    }
    return ans;
}

int main()
{
    // Example test case
    vector<int> start = {0, 5, 15};
    vector<int> end = {30, 10, 20};

    int result = minMeetingRooms(start, end);
    cout << "Minimum number of meeting rooms required: " << result << endl;

    return 0;
}

// ✅ Output for Above Example

// Minimum number of meeting rooms required: 2