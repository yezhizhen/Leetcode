// https://leetcode.com/problems/climbing-stairs/description/

class Solution
{
    int dp[46]{0, 1, 2, 3};

public:
    int climbStairs(int n)
    {
        if (n <= 0)
            return 0;
        if (dp[n] >= 1)
            return dp[n];
        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};