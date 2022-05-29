class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int last_prod = 1, ans = 0, left = 0;
        for(int right = 0; right < nums.size(); right++){
            if(nums[right] >= k)
            {    
                last_prod = 1, left = right + 1;
                continue;
            }
            
            last_prod *= nums[right];
            while(last_prod >= k)//shrink left until product is < k
                last_prod /= nums[left++];
            // we have last_prod * nums[right] < k
            ans += right - left + 1;
        }
        return ans;
    }
};