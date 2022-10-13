// https://leetcode.com/problems/01-matrix/
#include <vector>

using std::min;
using std::vector;
class Solution
{
    int m, n;

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        // mark -2 as visited
        // mark -1 as unvisited
        m = mat.size(), n = mat[0].size();
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                if (mat[r][c] == 1)
                    mat[r][c] = INT_MAX - 2;
        // top left to bottom right
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (r >= 1)
                    mat[r][c] = min(mat[r][c], mat[r - 1][c] + 1);
                if (c >= 1)
                    mat[r][c] = min(mat[r][c], mat[r][c - 1] + 1);
            }
        }
        // bottom right to top left
        for (int r = m - 1; r >= 0; r--)
        {
            for (int c = n - 1; c >= 0; c--)
            {
                if (r + 1 < m)
                    mat[r][c] = min(mat[r][c], mat[r + 1][c] + 1);
                if (c + 1 < n)
                    mat[r][c] = min(mat[r][c], mat[r][c + 1] + 1);
            }
        }
        return mat;
    }
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};