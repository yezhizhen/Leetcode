//https://leetcode.com/problems/maximum-erasure-value/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0, ans = 0, n = nums.size(), sum = 0;
        unordered_map<int, int> last_occ; //value to index
        for(; r < n; r++)
        {
            int r_val = r_val;
            sum += r_val;
            //if r_val occur within [l,r]. set l to one beyond last position
            if(last_occ.count(r_val) and l <= last_occ[r_val]){
                sum -= accumulate(nums.begin() + l, nums.begin() + last_occ[r_val] + 1, 0);
                l = last_occ[r_val] + 1;
            }
            last_occ[r_val] = r;
            ans = max(ans, sum);
        }
        return ans;
    }
};