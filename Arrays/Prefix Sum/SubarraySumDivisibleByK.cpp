#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    int cnt = 0, pf = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;

    for (int num : nums)
    {
        pf += num;
        int mod = pf % k;

        if (mod < 0)
            mod += k;

        if (mp.find(mod) != mp.end())
        {
            cnt += mp[mod];
            mp[mod]++;
        }
        else
        {
            mp[mod] = 1;
        }
    }
    return cnt;
}

int main()
{
    // 🔹 Example usage
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    cout << "Number of subarrays divisible by " << k << ": " << subarraysDivByK(nums, k) << endl;

    // 📝 Problem:
    // Given an integer array `nums` and an integer `k`, return the total number of continuous subarrays
    // whose sum is divisible by `k`.
    //
    // Example:
    // Input: nums = [4,5,0,-2,-3,1], k = 5
    // Output: 7
    //
    // Constraints:
    // - 1 <= nums.length <= 3 * 10^4
    // - -10^4 <= nums[i] <= 10^4
    // - 2 <= k <= 10^4

    return 0;
}
