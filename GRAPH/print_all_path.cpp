// https://leetcode.com/problems/all-paths-from-source-to-target/
#include <vector>
#include <queue>
using namespace std;

// bfs approach
class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        // use bfs, without visited
        int n = graph.size();
        queue<vector<int>> bfs;
        bfs.push({0});
        vector<vector<int>> ans;
        while (!bfs.empty())
        {
            auto path = bfs.front();
            bfs.pop();
            if (path.back() == n - 1)
            {
                ans.push_back(path);
                continue;
            }
            for (auto &neighbor : graph[path.back()])
            {
                auto tmp = path;
                tmp.push_back(neighbor);
                bfs.push(tmp);
            }
        }
        return ans;
    }
};

// dfs approach
class Solution
{
    int n;
    vector<int> path;
    vector<vector<int>> ans;

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        // because it is DAG. we can dfs without visited. No cycle.
        n = graph.size();
        dfs(0, graph);
        return ans;
    }

    void dfs(int node, vector<vector<int>> &graph)
    {
        path.push_back(node);
        if (node == n - 1)
        {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        // visit all neighbors
        for (auto &neighbor : graph[node])
            dfs(neighbor, graph);
        path.pop_back();
    }
};