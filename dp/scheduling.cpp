// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
#include <vector>
using std::max;
using std::min;
using std::swap;
using std::vector;

class Solution
{
public:
    // dp[s][d] = min_{end in [s, size - d]}
    //(max_{i in [s,end]} {job[i]} + dp[end+1][d-1])
    // because size - (end + 1) >= d- 1 as constraint
    int minDifficulty(vector<int> &jobDifficulty, int segments)
    {
        int n = jobDifficulty.size();
        if (n < segments)
            return -1;

        int d = 1;
        vector<int> dp(n);
        // init
        dp.back() = jobDifficulty.back();
        for (int i = n - 2; i >= 0; i--)
            dp[i] = max(dp[i + 1], jobDifficulty[i]);

        // draw the 2D dp. Can compress to 1D
        d = 2;
        vector<int> cur(n);
        for (; d <= segments; d++)
        {
            for (int s = n - 1; s >= 0; s--)
            {
                int cur_max = jobDifficulty[s];
                int res = INT_MAX;
                for (int end = s; end <= n - d; end++)
                {
                    cur_max = max(cur_max, jobDifficulty[end]);
                    res = min(res, cur_max + dp[end + 1]);
                }
                cur[s] = res;
            }
            swap(cur, dp);
        }
        return dp[0];
    }
};