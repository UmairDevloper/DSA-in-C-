// # Task Scheduler (LeetCode 621)

// ```cpp
/*
Problem Statement:
You are given a list of tasks represented by capital letters and a non-negative integer n. 
Each task takes one unit of time to execute, and each identical task must be separated 
by at least 'n' units of time (cooling period). The CPU can either execute a task or remain idle. 
Return the least number of units of time that the CPU will take to finish all the given tasks.

Approach Used:
- Count the frequency of each task (since only 26 possible tasks A-Z).
- Push frequencies into a max heap (priority_queue) to always pick the most frequent remaining task.
- Simulate task execution in cycles of size (n+1):
  - In each cycle, pop tasks from the heap, execute them (reduce their count), 
    and store unfinished tasks temporarily.
  - Push unfinished tasks back into the heap after the cycle.
- If heap is empty at the end, we only add the number of executed tasks in the last cycle.
- Otherwise, we add the full cycle length (n+1).
- Repeat until all tasks are finished.

Time Complexity: O(N log 26) ≈ O(N), where N is the number of tasks.
Space Complexity: O(26) = O(1), since at most 26 characters are stored.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        vector<int> v(26, 0);

        for (auto x : tasks) {
            v[x - 'A']++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (v[i] > 0) {
                pq.push(v[i]);
            }
        }

        while (!pq.empty()) {
            vector<int> temp;

            for (int i = 0; i < n + 1; i++) {
                if (!pq.empty()) {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for (int &i : temp) {
                if (i > 0) {
                    pq.push(i);
                }
            }

            if (pq.empty()) ans += temp.size();
            else ans += (n + 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    cout << sol.leastInterval(tasks, n) << endl; 
    // Expected Output: 8
    return 0;
}
