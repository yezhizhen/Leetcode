// https://leetcode.com/problems/longest-subsequence-with-limited-sum/
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // O(n logn  + m logm) time
    // O(1) extra space
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        sort(nums.begin(), nums.end());
        // compute prefix sum
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i], nums[i] = sum;
        // use binary search
        // find i s.t. nums[i] <= queries[i] and nums[i+1] > queries[i]
        for (int i = 0; i < queries.size(); i++)
            queries[i] = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
        return queries;
    }
};