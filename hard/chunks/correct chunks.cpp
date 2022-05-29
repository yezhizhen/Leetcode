//https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

class Solution {
    public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        auto arr_copy = arr;
        sort(arr_copy.begin(), arr_copy.end());
        
        int ans{}, unmatched{};
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; i++){
            int x = arr[i], y = arr_copy[i]; 
            
            cnt[x]++; 
            if(cnt[x] <= 0)
                unmatched --;
            else //increased discrepancy
                unmatched++;
            
            cnt[y]--;
            if(cnt[y] >= 0)
                unmatched--;
            else
                unmatched ++;
            
            if(unmatched == 0) ans++;
        }
        return ans;
        
    }

};