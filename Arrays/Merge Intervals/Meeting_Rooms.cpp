// 📥 Sample Input

// start = [0, 5, 15]
// end =   [30, 10, 20]
// ✅ Output: 2

// One room for [0,30], second for [5,10]

// [15,20] can reuse room after 10

// ✅ Full C++ Code (VS Code Ready)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate minimum number of meeting rooms required
int minMeetingRooms(vector<int> &start, vector<int> &end) {
    int n = start.size();

    int room = 0;
    int res = 0;

    // Step 1: Sort both start and end times
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0, j = 0;

    // Step 2: Traverse through all meetings
    while (i < n) {
        if (start[i] < end[j]) {
            // New meeting starts before the last one ends => need new room
            room++;
            i++;
        } else {
            // A meeting has ended => room freed
            room--;
            j++;
        }
        // Update max rooms used at any time
        res = max(res, room);
    }
    return res;
}

int main() {
    vector<int> start = {0, 5, 15};
    vector<int> end = {30, 10, 20};

    int result = minMeetingRooms(start, end);

    cout << "Minimum meeting rooms required: " << result << endl;

    return 0;
}

// 🖨️ Output
// // swift
// // Copy
// // Edit
// Minimum meeting rooms required: 2
// ⏱️ Time Complexity
// Sorting: O(n log n)

// Loop: O(n)

// Overall: O(n log n)