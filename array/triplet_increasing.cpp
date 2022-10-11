
#include <vector>
// https://leetcode.com/problems/increasing-triplet-subsequence/
using namespace std;
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int min_num = INT_MAX, min_mid_candidate = INT_MAX;
        for (int num : nums)
        {
            if (num > min_mid_candidate)
                return true;
            // this is a valid middle candidate
            if (num > min_num)
                min_mid_candidate = min(min_mid_candidate, num);
            else
                min_num = num;
        }
        return false;
    }
};