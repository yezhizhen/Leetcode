// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
#include <vector>
#include <queue>
using namespace std;
// with a 3D array for visited
class Solution
{
public:
    struct state
    {
        int x, y, k;
        state(int x, int y, int k) : x{x}, y{y}, k{k}
        {
        }
    };

    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1)
            return 0;
        // encode by "{m}-{n}-{remaining k}"
        bool explored[m][n][k + 1];
        memset(explored, false, sizeof(explored));
        explored[0][0][k];
        // BFS
        queue<state> bfs;
        int dirs[4][2]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        bfs.emplace(0, 0, k);
        int d = 0;
        while (!bfs.empty())
        {
            // sz many to explore at distance d
            int sz = bfs.size();
            for (int i = 0; i < sz; i++)
            {
                state s = bfs.front();
                bfs.pop();

                // check four directions
                for (auto &dir : dirs)
                {
                    int nx = s.x + dir[0], ny = s.y + dir[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                    {

                        // have to and can remove obstacle
                        if (grid[nx][ny])
                        {
                            if (s.k > 0)
                            {
                                if (nx == m - 1 && ny == n - 1)
                                    return d + 1;

                                if (!explored[nx][ny][s.k - 1])
                                    bfs.emplace(nx, ny, s.k - 1),
                                        explored[nx][ny][s.k - 1] = true;
                            }
                        }
                        else
                        {
                            if (nx == m - 1 && ny == n - 1)
                                return d + 1;
                            if (!explored[nx][ny][s.k])
                                bfs.emplace(nx, ny, s.k), explored[nx][ny][s.k] = true;
                        }
                    }
                }
            }
            d++;
        }
        return -1;
    }
};