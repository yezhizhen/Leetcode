class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int total_cnt{}, overlap{}, cnt_non_zero{};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                cnt_non_zero ++; 
                total_cnt += grid[i][j];
                if(i + 1 < m)
                    overlap += min(grid[i][j], grid[i+1][j]);
                if(j + 1 < n)
                    overlap += min(grid[i][j], grid[i][j+1]);
            }
        }
        return total_cnt * 4 + 2 * cnt_non_zero - overlap * 2;
        
    }
};