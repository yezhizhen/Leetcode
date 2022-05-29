//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
struct Data{
    int i1, i2;
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&](Data &d1, Data &d2){ return nums1[d1.i1] + nums2[d1.i2] > nums1[d2.i1] + nums2[d2.i2];};
        int sz1 = nums1.size(), sz2 = nums2.size();
        vector<Data> init; init.reserve(sz1);
        for(int i = 0; i < sz1; i++) init.push_back({i,0});
        priority_queue<Data, vector<Data>, decltype(cmp)> q(cmp, move(init));
        
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
};