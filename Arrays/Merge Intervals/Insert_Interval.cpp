// 📌 Problem Recap
// You are given a list of non-overlapping, sorted intervals, and a new interval. Insert it into the list such that the resulting list is also sorted and non-overlapping after merging where necessary.

// 📥 Example Input

// intervals = [[1,3],[6,9]]
// newInterval = [2,5]
// 🧠 Output: [[1,5],[6,9]]

// [1,3] and [2,5] overlap → merge to [1,5]

// ✅ Full C++ Code (VS Code Ready)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to insert and merge a new interval
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size();
    vector<vector<int>> res;

    int i = 0;

    // Step 1: Add intervals that end before newInterval starts (no overlap)
    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i]);
        i++;
    }

    // Step 2: Merge all overlapping intervals with newInterval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval); // Push the merged newInterval

    // Step 3: Add the remaining intervals
    while (i < n) {
        res.push_back(intervals[i]);
        i++;
    }

    return res;
}

// Helper function to print intervals
void printIntervals(const vector<vector<int>>& intervals) {
    cout << "[";
    for (size_t i = 0; i < intervals.size(); i++) {
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]";
        if (i != intervals.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    vector<vector<int>> intervals = {{1,3}, {6,9}};
    vector<int> newInterval = {2,5};

    vector<vector<int>> result = insert(intervals, newInterval);

    cout << "Merged intervals: ";
    printIntervals(result);

    return 0;
}

// 🖨️ Output

// Merged intervals: [[1,5],[6,9]]