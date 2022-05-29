class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        nums1.resize(unique(nums1.begin(),nums1.end()) - nums1.begin());
        nums2.resize(unique(nums2.begin(),nums2.end()) - nums2.begin());
        
        int p1 = 0, p2 = 0;
        while(p1 < nums1.size() and p2 < nums2.size())
        {
            if(nums1[p1] == nums2[p2])
                p1++, p2++;
            else{
                if(nums1[p1] < nums2[p2])
                    ans[0].push_back(nums1[p1++]);
                else
                    ans[1].push_back(nums2[p2++]);
            }
        }
        while(p1 < nums1.size())
            ans[0].push_back(nums1[p1++]);
        while(p2 < nums2.size())
            ans[1].push_back(nums2[p2++]);
        return ans;
    }
};