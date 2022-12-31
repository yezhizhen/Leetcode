// https://leetcode.com/problems/unique-paths-iii/
#include <vector>
using namespace std;

class Solution
{
    int ans = 0, visited_cnt = 0;
    int startx, starty, count_grid = 0;
    int dir[4][2]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        for (int x = 0; x < grid.size(); x++)
            for (int y = 0; y < grid[x].size(); y++)
            {
                if (grid[x][y] == 1)
                    startx = x, starty = y;

                if (grid[x][y] != -1)
                    count_grid++;
            }
        dfs(startx, starty, grid);
        return ans;
    }

    void dfs(int x, int y, vector<vector<int>> &grid)
    {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] < 0)
            return;
        if (grid[x][y] == 2)
        {
            if (visited_cnt + 1 == count_grid)
                ans++;
            return;
        }
        visited_cnt++;
        grid[x][y] = -2;
        // visit its neighbor
        for (auto &d : dir)
            dfs(x + d[0], y + d[1], grid);
        visited_cnt--;
        grid[x][y] = 0;
    }
};