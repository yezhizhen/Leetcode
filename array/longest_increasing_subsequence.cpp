class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
        // vector<int> dp{nums[0]}; 
        // for(int i = 1; i < nums.size(); i++)
        // {
            // if(nums[i] > dp.back())
                // dp.push_back(nums[i]);
            // else if(nums[i] == dp.back())
                // continue;
            // else{ //find j such that dp[j] < nums[i] and dp[j+1] > nums[i] 
                // auto it = upper_bound(dp.begin(), dp.end(), nums[i]);
                // if(it == dp.begin() or *(it-1) < nums[i])
                    // *it = nums[i];
            // }
        // }
        // return dp.size();
    // }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp{nums[0]}; //Let dp[i] be the smallest last element for the set of IS with length i + 1.
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > dp.back())
                dp.push_back(nums[i]);
            else if(nums[i] == dp.back())
                continue;
            else //find j such that dp[j] < nums[i] and dp[j+1] > nums[i]. dp[j+1] = nums[i]
                *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
        }
        return dp.size();
    }
    
};