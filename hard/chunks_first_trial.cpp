class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        return solve(arr, 0, arr.size() - 1);
    }
    
    //solve for [left, right]
    int solve(vector<int>& arr, int left, int right){
        if(left == right) return 1;
        int r = -1, max_val{INT_MIN};
        //scan from left to right
        for(int i = left; i <= right; i++){
            if(arr[i] < max_val)
                r = i;
            else
                max_val = arr[i];
        }
        if(r == -1)
            return right - left + 1;
        int l, min_val{INT_MAX};
        for(int i = right; i >= left; i--){
            if(arr[i] > min_val)
                l = i;
            else
                min_val = arr[i];
        }
        //whole array needs to be sorted. find out what remains there
        if(right == r and l == left)
        {
            
        }
        return right - left - r  + l +  solve(arr, l, r);
    }
    
};