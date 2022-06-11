//https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

//O(n) time O (n) space
class Solution {
    public:
    int minOperations(vector<int>& nums, int x) {
        //create a postfix sum map: sum -> length
        unordered_map<int, int> sum_len {{0, 0}};
        int sum = 0, n = nums.size();
        for(int len = 1; len <= n; len++){
            sum += nums[n - len];
            sum_len[sum] = len;
        }
        
        int ans = n + 1; //impossible result 
        //nothing from left
        if(sum_len.count(x))
            ans = sum_len[x];
        
        sum = 0; //left sum 
        //left_len: i + 1 < ans
        for(int i = 0; i < ans - 1 and sum <= x; i++){
            sum += nums[i];
            if(sum_len.count(x - sum)) //can get to x
            {
                int r_len = sum_len[x - sum];
                if(r_len + i + 1 <= n) //no crossing. valid
                    ans = min(ans, r_len + i + 1);
            }
        }
        return (ans == n + 1) ? -1 : ans;
    }
};



//O(n) time O (1) space
class Solution {
    public:
    int minOperations(vector<int>& nums, int x) {
        //create a postfix sum map: sum -> length
        int l = 0, r = 0, target = accumulate(nums.begin(), nums.end(), 0) - x;
        int sum = 0, n = nums.size(), ans = -1; //impossible result 
        
        while(r < n){
            sum += nums[r];
            while(l <= r and sum > target) //move left pointer 
                sum -= nums[l++];
            if(sum == target){
                ans = max(ans, r - l + 1);
            }
            r++;
        }
        return ans == -1 ? -1 : n - ans;
    }
};