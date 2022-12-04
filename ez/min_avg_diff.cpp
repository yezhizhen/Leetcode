// https://leetcode.com/problems/minimum-average-difference/

#include <vector>
#include <numeric>
using namespace std;
class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        int n = nums.size();
        long sum_r = accumulate(nums.begin(), nums.end(), 0L);
        long sum_l = 0, ans_val = abs(sum_r / n), ans = n - 1;
        for (int i = 0; i < n - 1; i++)
        {
            sum_l += nums[i], sum_r -= nums[i];
            int cur_diff = abs(sum_l / (i + 1) - sum_r / (n - i - 1));
            if (cur_diff < ans_val)
                ans_val = cur_diff, ans = i;
            else if (cur_diff == ans_val && i < ans)
                ans = i;
        }
        return ans;
    }
};