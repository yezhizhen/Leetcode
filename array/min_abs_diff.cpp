//https://leetcode.com/problems/minimum-absolute-difference-queries/
class Solution {
public:
    //nums betweeen 1, 100 
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int cnt[n + 1][101]{}; // [x][y] how many y in range [0...x - 1]   
        for(int i = 0; i < n; i++)
        {
            memcpy( cnt[i], cnt[i+1], sizeof(int) * 101);
            cnt[i+1][nums[i]]++;
        }
        vector return_val; return_val.reserve(queries.size());
        for(const auto &q: queries){
            int start = q[0], end = q[1];
            int last_value_alive = -1;
            int ans = INT_MAX;
            //occurernce is cnt[end+1][] - cnt[start][]
            for(int x = 1; x<= 100; x++ ){
                int cnt_x = cnt[end+1][x] - cnt[start][x];
                if(cnt_x > 0){
                    if(last_value_alive == -1)
                        last_value_alive = x;
                    else
                        ans = min(ans, x - last_value_alive);
                }
            }
            return_val.push_back(ans == INT_MAX ? -1 : ans);
            
        }
        return return_val;
    }
};