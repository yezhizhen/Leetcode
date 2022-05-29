//https://leetcode.com/problems/coin-change-2/
class Solution {
    int pre[5001]{},cur[5001]{}; // previous row, next row
    
    public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int cur_coin = coins[0];
        for(int j = 0; j * cur_coin <= amount; j++)
            pre[j * cur_coin] = 1;
        
        //bottom up
        for(int i = 1; i < n; i++){//all coins
            cur_coin = coins[i];
            for(int z = 0; z < amount; z++){//all pre values
                if(pre[z] == 0) continue;
                for(int j = 0; z + j * cur_coin <= amount; j++) //j: how many cur to use
                    cur[z + j * cur_coin]+= pre[z];
               
            }
            swap(pre, cur);
            memset(cur, 0, sizeof(int) * (1 + amount));
        }
        return pre[amount];
    }
};