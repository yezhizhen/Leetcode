// https://leetcode.com/problems/find-if-path-exists-in-graph/description/

#include <vector>
using namespace std;
// union find

class UF
{
    vector<int> parent, rank;

public:
    UF(int n) : parent(n), rank(n)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y)
    {
        int rx = find(x), ry = find(y);

        if (rx != ry)
        {
            if (rank[rx] < rank[ry])
                parent[rx] = ry;
            else if (rank[ry] < rank[rx])
                parent[ry] = rx;
            else
                parent[ry] = rx, rank[rx]++;
        }
    }
};

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        UF uf(n);
        for (auto &e : edges)
            uf.unite(e[0], e[1]);
        return uf.find(source) == uf.find(destination);
    }
};