// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
#include <vector>
#include <unordered_map>
using namespace std;
// 100% time 100% memory
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        int ans{0};
        vector<unordered_map<int, int>> cnt; // from difference to count
        // cnt[i] is the map from difference to count, ending in i.
        for (int num : nums)
        {
            unordered_map<int, int> tmp;
            for (int i = 0; i < cnt.size(); i++)
            {
                // would overflow and unable to form arithmetic
                long long res = num * 1LL - nums[i];
                if (abs(res) > 1431655765)
                    continue;
                auto it = cnt[i].find(res);
                int cur_cnt = it != cnt[i].end() ? it->second : 0;
                ans += cur_cnt, tmp[res] += cur_cnt + 1; // 1 for  just nums[i] and num
            }
            cnt.emplace_back(move(tmp));
        }
        return ans;
    }
};