// Input: section = [ 2, 4, 2, 4, 5], H = 8
// Output: 3
// Explanation: Participate will solve 3 questions per hour to solve all the questions within 8 hours.

// Input: section = [ 8, 11, 18, 20], H = 10
// Output: 7
// Explanation: Participate will solve 7 questions per hour to solve all the questions within 10 hours.

// C++ code for the above approach:
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool canSolveAll(vector<int> &sections, int speed, int h)
{
    int time = 0;
    for (int section : sections)
    {
        time += (section - 1) / speed + 1;
        if (time > h)
        {
            return false;
        }
    }
    return true;
}

int minSolvingSpeed(vector<int> &sections, int h)
{
    int left = 1;
    int right = *max_element(sections.begin(), sections.end());

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (canSolveAll(sections, mid, h))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

// Driver code
int main()
{
    vector<int> sectionss = {8, 11, 18, 20};
    int H = 10;

    // Function Call
    cout << minSolvingSpeed(sectionss, H);
    return 0;
}