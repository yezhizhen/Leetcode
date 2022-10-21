// https://leetcode.com/problems/contains-duplicate-ii/
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    // slow
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, vector<int>> occ;
        for (int i = 0; i < nums.size(); i++)
            occ[nums[i]].push_back(i);
        for (const auto &[_, indices] : occ)
        {
            for (int i = 1; i < indices.size(); i++)
            {
                if (indices[i] - indices[i - 1] <= k)
                    return true;
            }
        }
        return false;
    }
    // faster
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> occ;
        for (int i = 0; i < nums.size(); i++)
        {
            if (occ.count(nums[i]) && i - occ[nums[i]] <= k)
                return true;
            occ[nums[i]] = i;
        }
        return false;
    }
    // k + 1 window. fastest
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> occ;
        occ.reserve(k + 1);
        for (int i = 0; i < nums.size() && i <= k; i++)
        {
            if (occ.count(nums[i]))
                return true;
            occ[nums[i]] = i;
        }
        for (int i = k + 1; i < nums.size(); i++)
        {
            // remove the head
            occ.erase(nums[i - k - 1]);
            if (occ.count(nums[i]))
                return true;
            occ[nums[i]] = i;
        }
        return false;
    }
};