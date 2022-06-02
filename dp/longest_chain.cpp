class Solution {
    
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        auto it = unique(pairs.begin(), pairs.end(),
            [](auto &p1, auto &p2)
            {return p1[0] == p2[0];}); //remove those unnecessarily long
        pairs.resize(it - pairs.begin());
        int ans = 0, last_start = INT_MAX;
        for(auto it = pairs.rbegin(); it != pairs.rend(); it++)
        {
            int start = (*it)[0], end = (*it)[1];
            if(end < last_start)
                ans++, last_start = start;
        }
        return ans;
    }
};