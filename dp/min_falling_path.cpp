// https://leetcode.com/problems/minimum-falling-path-sum/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> pre_row = matrix[0];
        vector<int> cur_row(n);

        for (int r = 1; r < n; r++)
        {
            for (int c = 0; c < n; c++)
                cur_row[c] = matrix[r][c] + min({pre_row[c], c + 1 < n ? pre_row[c + 1] : INT_MAX,
                                                 c > 0 ? pre_row[c - 1] : INT_MAX});
            swap(cur_row, pre_row);
        }
        return *min_element(pre_row.begin(), pre_row.end());
    }
};