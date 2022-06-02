//https://leetcode.com/problems/transpose-matrix/
class Solution {
public:
    //extra place
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for(int r = 0; r < m; r++)
            for(int c = 0; c < n; c++)
                ans[c][r] = matrix[r][c];
        return ans;
        
    }
};