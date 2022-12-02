// https://leetcode.com/problems/find-players-with-zero-or-one-losses/
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<vector<int>> res(2);
        unordered_map<int, int> loss_cnt;
        for (auto &match : matches)
        {
            loss_cnt[match[1]]++;
            if (loss_cnt.find(match[0]) == loss_cnt.end())
                loss_cnt[match[0]] = 0;
        }
        for (const auto &[player, loss] : loss_cnt)
            if (loss == 1)
                res[1].push_back(player);
            else if (loss == 0)
                res[0].push_back(player);
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }
};