// 📌 Problem Summary
// Given an array of intervals where intervals may overlap, your task is to merge all overlapping intervals and return the result in sorted, non-overlapping form.

// 📥 Example Input

// intervals = [[1,3],[2,6],[8,10],[15,18]]
// ✅ Output: [[1,6],[8,10],[15,18]]
// 💡 Because [1,3] and [2,6] overlap and merge into [1,6]

// ✅ Full C++ Program (VS Code Ready)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> ans;

    if(n == 0) return ans;

    // Step 1: Sort intervals based on starting time
    sort(intervals.begin(), intervals.end());

    vector<int> tintervals = intervals[0];

    // Step 2: Merge overlapping intervals
    for(auto it : intervals){
        if(it[0] <= tintervals[1]) {
            // Overlapping: extend the end time
            tintervals[1] = max(it[1], tintervals[1]);
        } else {
            // No overlap: push the current merged interval
            ans.push_back(tintervals);
            tintervals = it;
        }
    }

    // Step 3: Push the last interval
    ans.push_back(tintervals);

    return ans;
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
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    vector<vector<int>> result = merge(intervals);

    cout << "Merged intervals: ";
    printIntervals(result);

    return 0;
}

// 🖨️ Output

// Merged intervals: [[1,6],[8,10],[15,18]]
