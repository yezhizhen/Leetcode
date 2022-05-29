//https://leetcode.com/problems/unique-paths-ii/
class Solution {
    int ans[100][100], m, n;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 or obstacleGrid[0][0] == 1) return 0;
        memset(ans, -1, sizeof(ans));
        ans[m - 1][n - 1] = 1;
        dfs(0,0,obstacleGrid);
        return ans[0][0];
    }
    
    //requirement: called on valid coordinates
    int dfs(int r, int c, vector<vector<int>>& g){
        if(ans[r][c] >= 0)
            return ans[r][c];
        int res = 0;
        if(r + 1 < m and g[r+1][c] == 0)
            res += dfs(r+1,c,g);
        if(c + 1 < n and g[r][c+1] == 0)
            res += dfs(r,c+1,g);
        return ans[r][c] = res;
    }
    
};