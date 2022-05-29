//https://leetcode.com/problems/smallest-string-with-swaps/solution/
struct DS{
    DS(int sz):rank(sz, 0){
        parent.reserve(sz);
        for(int i = 0; i < sz; i++)
            parent.push_back(i);
    }
    
    int find(int node){
        if(parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    
    void uni(int x, int y){
        int rx = find(x), ry = find(y);
        if(rank[rx] > rank[ry])
            parent[ry] = rx;
        else if(rank[rx] < rank[ry])
            parent[ry] = rx;
        else{
            parent[ry] = rx;
            rank[rx]++;
        }
    }
private:
    vector<int> parent,rank;
};

class Solution {
    public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DS ds(n);
        for(const auto &p:pairs)
            ds.uni(p[0],p[1]);
        //Find all clusters
        unordered_map<int,vector<int>> clusters;
        for(int i = 0; i < n; i++)
            clusters[ds.find(i)].push_back(i);
        
        for(const auto &[rt, group]: clusters){ //group already in increasing order
            string tmp; tmp.reserve(group.size());
            for(int i: group)
                tmp += s[i];
            sort(tmp.begin(), tmp.end());
            for(int i = 0; i < group.size(); i++)
                s[group[i]] = tmp[i];
        }
        return s;
    }
};