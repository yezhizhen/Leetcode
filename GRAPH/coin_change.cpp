//https://leetcode.com/problems/coin-change/
class Solution {
    static const int impossible = -1;
    int ans[10001];//how many coins needed to achieve that number
public:
    Solution(){
        fill_n(ans,10001,-2); //-2: not marked yet
        ans[0] = 0;
    }

    int coinChange(vector<int>& coins, int amount) {
        if(ans[amount] >= -1) return ans[amount]; 
        int res = INT_MAX;
        for(int c:coins)
            if(c <= amount){
                int ret_val;
                if((ret_val = coinChange(coins, amount - c)) == impossible)
                    continue;
                res = min(res, 1 + ret_val);
            }
        return ans[amount] = (res == INT_MAX ? impossible: res);
    }
};