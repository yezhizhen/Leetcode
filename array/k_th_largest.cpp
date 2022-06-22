//https://leetcode.com/problems/kth-largest-element-in-an-array/

//O(nlogn) time
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[k - 1];
    }
};


//heap
//O(nlogn) time
//O(k) space
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        
        for(int i = 0; i < k; i++)
            q.push(nums[i]);
        //with k elements.
        for(int i = k; i < nums.size(); i++){
            if(nums[i] > q.top()){
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};

//Quickselect
//O(n) time in average
//O(1) extra space. Tail recursion
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, nums.size() - k, 0, nums.size() - 1);
    }
    
    //quick select in range [left, right]
    int quickselect(vector<int> &nums, int target_ind, int left, int right){
        //pivot: median one. Could use random if you want
        int pivot_num = nums[(left + right) / 2];
        swap(nums[right], nums[(left+right) / 2]);//put pivot at end first
        int r = right - 1, l = left;
        
        //put those smaller than pivot to the left; larger to the right
        while(l <= r){
            if(nums[l] <= pivot_num)
                l++;
            else
                swap(nums[l], nums[r--]);
        }
        //now, nums in range [0, l - 1 (which equals r)] <= pivot
        //                   [l,...] > pivot
        //put pivot back
        swap(nums[right], nums[l]);
        //pivot is the target one!
        if(l == target_ind)
            return nums[l];
        else if(l < target_ind)
            return quickselect(nums, target_ind, l + 1, right);
        else
            return quickselect(nums, target_ind, left, l - 1);
    }
};
