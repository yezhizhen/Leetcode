//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
class Solution {
    using Data = pair<int,int>;
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int sz1 = nums1.size(), sz2 = nums2.size();
        int l = nums1[0] + nums2[0], h = nums1[sz1 - 1] + nums2[sz2 - 1];
        
        vector<vector<int>> ans;
        while(k and not q.empty()){
            auto [i1, i2] = q.top(); q.pop();
            ans.push_back({nums1[i1], nums2[i2]});
            if(i2 < sz2 - 1)
                q.push({i1, i2+1});
            k--;
        }
        return ans;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //binary search.
        int n = matrix.size();
        int l{matrix[0][0]}, h {matrix[n-1][n-1]}, mid;
        while(l < h)
        {
            mid = l + (h - l) / 2;
            int cnt_smaller{}, cnt_include{};
            int last_ind_1 = n, last_ind_2 = n; //make use of property that column also sorted
            for(auto &row: matrix){
                auto it = lower_bound(row.begin(), row.begin() + last_ind_1, mid);
                cnt_smaller += it - row.begin(); last_ind_1 = min<int>(n, it - row.begin() + 1);
                int tmp = upper_bound(it, row.begin() + last_ind_2, mid) - row.begin();
                cnt_include += tmp; last_ind_2 = min<int>(n, tmp + 1);
            }
            
            if(cnt_smaller >= k)
                h = mid - 1;
            else{
                if(cnt_include >= k)
                    return mid;
                else
                    l = mid + 1;
            }
        }
        return l + (h - l) / 2;
    }
    
};