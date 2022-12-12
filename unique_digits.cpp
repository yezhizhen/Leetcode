// https://leetcode.com/problems/count-numbers-with-unique-digits/
class Solution
{
    int dp[8]{1};

public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        pre_compute(n - 1);
        return solve(n);
    }

    int solve(int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        return solve(n - 1) + 9 * dp[n - 1];
    }
    // compute P(9,n)
    void pre_compute(int n)
    {
        for (int n_i = 1; n_i <= n; n_i++)
            dp[n_i] = dp[n_i - 1] * (10 - n_i);
    }
};

// iterative

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        if (n == 1)
        {
            return 10;
        }
        int ans = 10, cur = 9;
        for (int i = 0; i < n - 1; ++i)
        {
            cur *= 9 - i;
            ans += cur;
        }
        return ans;
    }
};
