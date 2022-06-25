//https://leetcode.com/problems/non-decreasing-array/discuss/2193124/C%2B%2B-oror-O(n)-100-runtime-oror-Commented
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i = 0;
        for(; i < nums.size() - 1 and nums[i+1] >= nums[i]; i++);
        
        if(i == nums.size() - 1) return true;
        
        //we at first i s.t. nums[i+1] < nums[i]
        
        //fix 1: try set nums[i]:= nums[i+1]. see if it works
        if(i == 0 or nums[i + 1] >= nums[i - 1]){
            int j = i + 1;
            for(; j < nums.size() - 1 and nums[j+1] >= nums[j]; j++);
            if(j == nums.size() - 1)
                return true;
            else
                return false;
        }
        //fix 2: try set nums[i+1] := nums[i]
        nums[i+1] = nums[i];
        int j = i + 1;
        for(;j < nums.size() - 1 and nums[j + 1] >= nums[j];j++);
        if(j == nums.size() - 1)
            return true;
        else return false;
    }
};