#include <cstring>
class Solution
{
    int ans[31][1001];
    const int mod = (1e9 + 7);

public:
    int numRollsToTarget(int n, int k, int target)
    {
        memset(ans, -1, sizeof(ans));
        for (int i = 1; i <= target; i++)
            if (i <= k)
                ans[1][i] = 1;
            else
                ans[1][i] = 0;
        return solve(n, k, target);
    }

    int solve(int n, int k, int target)
    {
        if (ans[n][target] != -1)
            return ans[n][target];
        int res = 0;
        for (int cur = 1; cur <= k && cur <= target; cur++)
            res = (res + solve(n - 1, k, target - cur)) % mod;

        return ans[n][target] = res;
    }
};