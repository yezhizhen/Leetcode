//https://leetcode.com/problems/shortest-path-in-binary-matrix/
class Solution {
    int n;
    int dir[8][2]{{-1,-1},{-1,0},{-1,1},{0,1},{0,-1},{1,0},{1,-1},{1,1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        if(grid[0][0]) return -1;
        queue<pair<int,int>> bfs; bfs.emplace(0, 0); grid[0][0] = 1;
        int ans = 0;
        while(not bfs.empty()){
            int sz = bfs.size();
            ans++;
            for(int i = 0; i < sz; i++){
                auto [r,c]= bfs.front(); bfs.pop();
                if(r == n - 1 and c == n - 1) return ans;
                for(auto &[r_off,c_off]: dir){
                    int nr = r + r_off, nc = c + c_off;
                    if(nr >= 0 and nr < n and nc >= 0 and nc < n and grid[nr][nc] == 0){
                        bfs.emplace(nr, nc);
                        grid[nr][nc] = 1;
                    }
                }
            }
        }
        return -1;
    }
};