// https://leetcode.com/problems/toeplitz-matrix/
#include <vector>

using namespace std;
class Solution
{
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        // check main diagonal
        for (int i = 1; i < m && i < n; i++)
            if (matrix[i][i] != matrix[i - 1][i - 1])
                return false;

        // lower triangular diagonal
        for (int start_r = 1; start_r < m; start_r++)
        {
            for (int offset = 1; offset + start_r < m && offset < n; offset++)
                if (matrix[offset + start_r][offset] != matrix[offset + start_r - 1][offset - 1])
                    return false;
        }
        // upper triangular diagonal
        for (int start_c = 1; start_c < n; start_c++)
        {
            for (int offset = 1; offset < m && offset + start_c < n; offset++)
                if (matrix[offset][offset + start_c] != matrix[offset - 1][offset + start_c - 1])
                    return false;
        }
        return true;
    }

    bool isToeplitzMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        // check main diagonal
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
        return true;
    }
};