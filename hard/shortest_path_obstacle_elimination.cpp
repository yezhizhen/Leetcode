// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;
class Solution
{
public:
    struct state
    {
        int x, y, k;
        state(int x, int y, int k) : x{x}, y{y}, k{k}
        {
        }
        bool operator==(const state &s2) const
        {
            return this->x == s2.x && this->y == s2.y && this->k == s2.k;
        }
    };

    struct hasherForState
    {
        size_t operator()(const state &s) const
        {
            return s.k + 1681 * s.x + 41 * s.y;
        }
    };

    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1)
            return 0;
        // encode by "{m}-{n}-{remaining k}"
        unordered_set<state, hasherForState> explored;
        explored.emplace(0, 0, k);
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
                                state next{nx, ny, s.k - 1};
                                if (!explored.count(next))
                                    bfs.emplace(nx, ny, s.k - 1),
                                        explored.insert(move(next));
                            }
                        }
                        else
                        {
                            if (nx == m - 1 && ny == n - 1)
                                return d + 1;
                            state next{nx, ny, s.k};
                            if (!explored.count(next))
                                bfs.emplace(nx, ny, s.k), explored.insert(move(next));
                        }
                    }
                }
            }
            d++;
        }
        return -1;
    }
};