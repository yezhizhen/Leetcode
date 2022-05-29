//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
//note that there can not be any cycle, due to strict increasing constraint
class Solution {
    int m, n;
    int ans[200][200];
    int dir[4][2]{{-1,0},{1,0},{0,-1},{0,1}};
    
    //called on valid coordinates
    int dfs(int r, int c, const vector<vector<int>>& matrix){
        if(ans[r][c] >= 0) return ans[r][c];
        int max_path = 1;
        for(auto &d: dir){
            int nr = r + d[0], nc = c + d[1];
            if(nr >= 0 and nr < m and nc >= 0 and nc < n and matrix[nr][nc] > matrix[r][c])
                max_path = max(max_path, 1 + dfs(nr,nc,matrix));
        }
        return ans[r][c] = max_path;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(ans, -1, sizeof(ans));
        m = matrix.size(), n = matrix[0].size();
        int max_ans = 0;
        for(int r = 0; r < m; r++)
            for(int c = 0; c < n; c++)
                max_ans = max(max_ans, dfs(r,c,matrix));
        return max_ans;
    }
};