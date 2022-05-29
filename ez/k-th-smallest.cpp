//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
class Solution {
public:
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