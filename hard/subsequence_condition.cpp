//https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
class Solution {
    int n;
    vector<int> dp;
    const static int mod = 1e9 + 7;
    //compute on the fly. no pre compute
    int compute_power(int n){
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (compute_power(n - 1) << 1) % mod;
    }
    
public:
    int numSubseq(vector<int>& nums, int target) {
        n = nums.size();
        dp.assign(n, -1);
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int cur_min = nums[i], max_allowed = target - cur_min;
            if(cur_min > max_allowed)   break;
            //find first larger than target - nums[i]
            int count = upper_bound(nums.begin() + i, nums.end(), max_allowed) - nums.begin() - i - 1;
            ans += compute_power(count); ans %= mod;
        }
        return ans;
    }
};