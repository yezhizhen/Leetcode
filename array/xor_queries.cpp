#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();
        vector<int> dp(n + 1);
        int tmp = 0;
        for (int i = 0; i < n; i++)
            tmp ^= arr[i], dp[i + 1] = tmp;

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &v : queries)
            ans.push_back(dp[v[1] + 1] ^ dp[v[0]]);
        return ans;
    }
};