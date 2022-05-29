//https://leetcode.com/problems/maximum-number-of-points-with-cost/
class Solution {
    public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long> dp(n, 0), copy; //dp[i]: denotes the best contribution when picking column i at next row
 
        for(int r = 0; r < m - 1; r++){
            for(int c = 0; c < n; c++)
                dp[c] += points[r][c]; //raw contribution
            copy = dp;
            for(int i = 1; i < n; i++)//scan from left to right. adjusted contribution from left
                dp[i] = max(dp[i], dp[i-1] - 1); 
            for(int i = n - 2; i >= 0; i--)//scan from right to left. copy is adjusted contribution from right
                copy[i] = max(copy[i], copy[i+1] - 1), dp[i] = max(dp[i], copy[i]);
            
        }
        long ans{};
        for(int c = 0; c < n; c++)
                ans = max(ans, dp[c] + points[m - 1][c]);
        
        return ans;
    }
};