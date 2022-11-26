// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
#include <vector>
using namespace std;

struct UF
{
    int parts;
    vector<int> parent, rank;

    UF(int n) : parent(n), rank(n), parts(n)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        int rx = find(x), ry = find(y);
        if (rx == ry)
            return;
        if (rank[rx] < rank[ry])
            parent[rx] = ry;
        else if (rank[ry] < rank[rx])
            parent[ry] = rx;
        else
            parent[rx] = ry,
            rank[ry]++;
        parts--;
    }
};

class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        UF uf(stones.size());
        for (int i = 0; i < stones.size(); i++)
        {
            // check intersect with previous
            for (int j = 0; j < i; j++)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    uf.unite(i, j);
        }
        return stones.size() - uf.parts;
    }
};