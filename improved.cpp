//https://leetcode.com/problems/coin-change-2/
class Solution {
    int dp[5001]{}; // previous row, next row
    
    public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp[0] = 1;
        //bottom up
        for(int cur_coin: coins){//all coins
            for(int z = 0; z + cur_coin <= amount; z++){//all pre values
                dp[z + cur_coin] += dp[z];
            }
        }
        return dp[amount];
    }
};