#include <vector>
using namespace std;

// https://leetcode.com/problems/sum-of-subarray-minimums/
class Solution
{
    vector<int> inc_stack;
    const int mod = 1e9 + 7;

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int ans = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            while (!inc_stack.empty() && arr[inc_stack.back()] >= arr[i])
            {
                int ind = inc_stack.back();
                inc_stack.pop_back();
                ans = (ans + (i - ind) * (inc_stack.empty() ? ind + 1 : ind - inc_stack.back()) * arr[ind]) % mod;
            }
            inc_stack.push_back(i);
        }
        // empty the stack
        while (!inc_stack.empty())
        {
            int ind = inc_stack.back();
            inc_stack.pop_back();
            ans = (ans + (arr.size() - ind) * (inc_stack.empty() ? ind + 1 : ind - inc_stack.back()) * arr[ind]) % mod;
        }
        return ans;
    }
};