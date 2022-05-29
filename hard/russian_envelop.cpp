class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
        [](const auto &e1,const auto &e2){return tie(e1[0], e2[1]) < tie(e2[0],e1[1]);});
        vector<int> dp{envelopes[0][1]}; //focus on y coordinates now. this guaranted to be increasing
        for(int i = 1; i < envelopes.size(); i++)
        {
            int cur_y = envelopes[i][1];
            if( cur_y > dp.back())
                dp.push_back(cur_y);
            else //find j such that dp[j] < cur_y and dp[j+1] > cur_y. update dp[j+1] = cur_y 
                *lower_bound(dp.begin(), dp.end(), cur_y) = cur_y;
        }
        return dp.size();
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp{nums[0]}; 
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > dp.back())
                dp.push_back(nums[i]);
            else //find j such that dp[j] < nums[i] and dp[j+1] > nums[i] 
                *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
        }
        return dp.size();
    }
    
};