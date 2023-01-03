// https://leetcode.com/problems/delete-columns-to-make-sorted/

#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int m = strs.size(), n = strs[0].size();
        int ans = 0;
        for (int y = 0; y < n; y++)
        {
            bool unsorted = false;
            for (int x = 1; x < m; x++)
            {
                if (strs[x][y] < strs[x - 1][y])
                {
                    unsorted = true;
                    break;
                }
            }
            ans += unsorted;
        }
        return ans;
    }
};