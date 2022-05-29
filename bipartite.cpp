//https://leetcode.com/problems/is-graph-bipartite/
struct UF
{
    int n;
    vector<int> p;
    UF(int n_): n(n_),p(n_)
    {
        for(int i = 0; i < n; i++)
        p[i] = i;
    }
    
    int find(int x)
    {
        if(x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    
    //return false if already connected
    bool uni(int x, int y)
    {
        int rx = find(x), ry = find(y);
        if(rx == ry)
        return false;
        p[rx] = ry;
        return true;
        
    }
    
    
};

class Solution
{
    public:
    bool isBipartite(const vector<vector<int>>& graph)
    {
        int n = graph.size();
        UF uf(n);
        
        for(int i = 0; i < n; i++)
        {
            const auto &e = graph[i];
            for(const int j: e) 
                if (uf.find(i) == uf.find(j))
                    return false;
            //those in e cannot be same set of i. therefore make them in the same set
            for(int z = 1; z < e.size(); z++)
                uf.uni(e[z-1], e[z]);
        }
        return true;
    }
};