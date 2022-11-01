// https://leetcode.com/problems/where-will-the-ball-fall/

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n);
        for (int start_c = 0; start_c < n; start_c++)
        {
            int cur_c = start_c, cur_r = 0;
            for (; cur_r < m; cur_r++)
            {
                if (grid[cur_r][cur_c] == 1)
                {
                    if (cur_c == n - 1 || grid[cur_r][cur_c + 1] == -1)
                    {
                        res[start_c] = -1;
                        break;
                    }
                    else
                        cur_c++;
                }
                else
                {
                    if (grid[cur_r][cur_c] == -1)
                    {
                        if (cur_c == 0 || grid[cur_r][cur_c - 1] == 1)
                        {
                            res[start_c] = -1;
                            break;
                        }
                        else
                            cur_c--;
                    }
                }
            }
            if (cur_r == m)
                res[start_c] = cur_c;
        }
        return res;
    }
};