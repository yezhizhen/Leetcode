//https://leetcode.com/problems/range-sum-query-2d-immutable/
class NumMatrix {
    int m, n;
    vector<vector<int>> dp; //dp[r][c]: sum region from (0, 0) to (r , c)
public:
    NumMatrix(vector<vector<int>>& matrix): m(matrix.size()), n(matrix[0].size()),dp(m,vector<int>(n)){
        int cur_row_sum = 0;
        for(int c = 0; c < n; c++)
            cur_row_sum += matrix[0][c], dp[0][c] = cur_row_sum;
        
        for(int r = 1; r < m; r++){
            cur_row_sum = 0;
            for(int c = 0; c < n; c++)
                cur_row_sum += matrix[r][c], dp[r][c] = dp[r-1][c] + cur_row_sum;
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) { //make use of dp. O(1) per call
        return dp[r2][c2] - (r1 > 0 ? dp[r1-1][c2] : 0) - (c1 > 0 ? dp[r2][c1-1] : 0)+ 
              ((r1 > 0 and c1 > 0) ? dp[r1 - 1][c1 - 1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */