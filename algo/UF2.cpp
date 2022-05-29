struct UF
{
    vector<int> p;
    int part;

    UF(int n): p(n), rank(n), part(n - 1)
    {
        for(int i = 0; i < n; i++)
            p[i] = i;
    }

    int find(int node)
    {
        if(node == p[node])
            return node;
        return p[node] = find(p[node]);
    }

    void uni(int x, int y)
    {
        int rx = find(x), ry = find(y);
        if(rx == ry) return;
        if(rank[rx] > rank[ry])
            p[ry] = rx;
        else if(rank[rx] < rank[ry])
            p[rx] = ry;
        else
        {
            p[rx] = ry;
            rank[ry]++;
        }
        part--;
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }

private:
    vector<int> rank;
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges)
    {
        int m = edges.size(), used = 0;
        //build alice's edge
        UF ufa(n + 1), ufb(n + 1);

        for(auto &e: edges)
        {
            if(e[0] == 3)
            {
                if(not ufa.connected(e[1],e[2]) or not ufb.connected(e[1],e[2]))
                {
                    ufa.uni(e[1],e[2]);
                    ufb.uni(e[1],e[2]);
                    used++;
                }
            }
        }
        //now, check a
        for(auto &e: edges)
        {
            if(e[0] == 1 and ufa.part != 1)
            {
                if(not ufa.connected(e[1],e[2]))
                {
                    used++;
                    ufa.uni(e[1],e[2]);
                }
            }
            else if(e[0] == 2 and ufb.part!= 1)
            {
                if(ufb.part == 1)
                    break;
                if(not ufb.connected(e[1],e[2]))
                {
                    used++;
                    ufb.uni(e[1],e[2]);
                }
            }
        }
        if(ufa.part > 1 or ufb.part > 1)    return -1;

        return m - used;
    }
};