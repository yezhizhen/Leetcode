// https://leetcode.com/problems/longest-common-subsequence/description/
#include <string>
using namespace std;

class Solution
{
    int dp[1001][1001]{0};

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (text1[i] == text2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[m][n];
    }
};

// beats 100% time 100% memory
//  compressed dp
// use only 1 array, instead of 2.
class Solution
{
    int dp[1001]{0};

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        int dp_i_j = 0, tmp;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                tmp = dp[j + 1];
                if (text1[i] == text2[j])
                    dp[j + 1] = dp_i_j + 1;
                else
                    dp[j + 1] = max(dp[j + 1], dp[j]);
                dp_i_j = tmp;
            }
            dp_i_j = 0;
        }
        return dp[n];
    }
};