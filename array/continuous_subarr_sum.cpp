// https://leetcode.com/problems/continuous-subarray-sum/
#include <vector>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    // check if x mod k = 0 exists for some prefix sum x
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        if (nums.size() == 1)
            return false;
        int cur_sum = nums[0], pre_sum_i_minus_2 = 0;
        unordered_set<int> occ_up_to_i_minus_2{0};

        for (int i = 1; i < nums.size(); i++)
        {
            pre_sum_i_minus_2 = cur_sum;
            cur_sum = (cur_sum + nums[i]) % k;
            if (occ_up_to_i_minus_2.count(cur_sum))
                return true;
            occ_up_to_i_minus_2.insert(pre_sum_i_minus_2 % k);
        }
        return false;
    }
};
