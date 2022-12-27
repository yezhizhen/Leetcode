// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        // compute difference array
        auto &diff = rocks;
        int n = rocks.size();
        for (int i = 0; i < n; i++)
            diff[i] = capacity[i] - rocks[i];
        sort(diff.begin(), diff.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (additionalRocks >= diff[i])
                ans++, additionalRocks -= diff[i];
        return ans;
    }
};