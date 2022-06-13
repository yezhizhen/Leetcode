//https://leetcode.com/problems/triangle/submissions/
class Solution {
    
public:
    //can do in-place to by using the triangle array..
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = triangle[0][0];
        for(int r = 1; r < n; r++){
            //fill dp[r][r] first
            dp[r] = dp[r-1] + triangle[r][r];
            //have to fill in reverse order.
            for(int c = r - 1; c >= 1; c--)
                dp[c] = min(dp[c], dp[c-1]) + triangle[r][c];
            //fill dp[r][0]
            dp[0] = dp[0] + triangle[r][0];
        }
        return *min_element(dp, dp + n);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i =triangle.size()-2;i>=0;i--){
         for(int j=0;j<triangle[i].size();j++){    
             triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]); }}
    
        return triangle[0][0];
    }
    
    
};