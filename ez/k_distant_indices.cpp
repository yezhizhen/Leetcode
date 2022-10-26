#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        int prev_right = -1;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == key)
            {
                for (int j = max(prev_right + 1, i - k); j <= i + k; j++)
                {
                    if (j == nums.size())
                        return res;
                    res.push_back(j);
                }
                prev_right = i + k;
            }
        }
        return res;
    }
};