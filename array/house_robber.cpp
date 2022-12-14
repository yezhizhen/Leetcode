// https://leetcode.com/problems/house-robber/
#include <vector>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int pre_taken_max = nums[0], pre_not_taken_max = 0, cur_taken, cur_not_taken;
        for (int i = 1; i < nums.size(); i++)
        {
            cur_taken = pre_not_taken_max + nums[i];
            cur_not_taken = max(pre_not_taken_max, pre_taken_max);
            pre_not_taken_max = cur_not_taken, pre_taken_max = cur_taken;
        }
        return max(pre_not_taken_max, pre_taken_max);
    }
};