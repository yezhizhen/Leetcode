// https://leetcode.com/problems/set-mismatch/
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int duplicated, removed = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            // should be i+1
            if (nums[i] == nums[i + 1])
                duplicated = nums[i];
            if (nums[i] + 1 < nums[i + 1])
                removed = nums[i] + 1;
        }
        return {duplicated, nums.back() != nums.size() ? static_cast<int>(nums.size()) : removed};
    }
};