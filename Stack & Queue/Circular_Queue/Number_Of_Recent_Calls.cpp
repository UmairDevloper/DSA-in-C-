// # Number of Recent Calls

// ```cpp
/*
Problem Statement:
You have a RecentCounter class that counts the number of requests (pings) 
that happened in the past 3000 milliseconds (including the current one).
Implement the function ping(int t) that records a new ping at time t (in ms) 
and returns the number of pings that have happened in the inclusive range [t - 3000, t].

Approach Used:
- Use a queue<int> to store the times of each ping.
- Push the current time 't' into the queue.
- Remove (pop) all the times from the front of the queue that are less than t - 3000.
- The remaining elements in the queue represent the valid pings.
- Return the size of the queue.

Time Complexity: O(1) amortized per ping (each element pushed and popped at most once).
Space Complexity: O(n), where n is the number of pings within the last 3000 ms.
*/

#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
public:
    queue<int> q;

    int ping(int t) {
        q.push(t);
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

int main() {
    RecentCounter rc;
    cout << rc.ping(1) << endl;     // Output: 1
    cout << rc.ping(100) << endl;   // Output: 2
    cout << rc.ping(3001) << endl;  // Output: 3
    cout << rc.ping(3002) << endl;  // Output: 3
    return 0;
}
