// https://leetcode.com/problems/minimum-genetic-mutation/

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    // same length 8
    bool adjacent(string &s1, string &s2)
    {
        int res = 0;
        for (int i = 0; i < 8; i++)
            res += (s1[i] != s2[i]);
        return res == 1;
    }

    int minMutation(string start, string end, vector<string> &bank)
    {
        int n = bank.size();

        // end index
        int end_index = -1;
        for (int i = 0; i < n; i++)
            if (bank[i] == end)
            {
                end_index = i;
                break;
            }
        if (end_index == -1)
            return -1;
        if (adjacent(start, end))
            return 1;

        vector<int> neighbor[n];
        // build graph
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                if (adjacent(bank[i], bank[j]))
                    neighbor[i].push_back(j),
                        neighbor[j].push_back(i);
        }

        bool visited[n];
        memset(visited, false, sizeof(visited));
        queue<int> bfs;
        for (int i = 0; i < n; i++)
            if (adjacent(bank[i], start))
                bfs.push(i), visited[i] = true;

        int d = 1;
        while (!bfs.empty())
        {
            d++;

            int sz = bfs.size();
            for (int _ = 0; _ < sz; _++)
            {
                int cur = bfs.front();
                bfs.pop();
                // find its unvisited neighbor
                for (int nei : neighbor[cur])
                    if (!visited[nei])
                    {
                        if (nei == end_index)
                            return d;
                        bfs.push(nei), visited[nei] = true;
                    }
            }
        }
        return -1;
    }
};