#include <queue>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        queue<int> bfs;
        vector<bool> visited(n);
        visited[0] = true;
        bfs.push(0);

        while (!bfs.empty())
        {
            int cur = bfs.front();
            bfs.pop();
            if (cur + nums[cur] >= n - 1)
                return true;
            for (int i = 1; i <= nums[cur] && cur + i < n; i++)
                if (!visited[cur + i])
                {
                    bfs.push(cur + i);
                    visited[cur + i] = true;
                }
        }
        return false;
    }
};

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int max_reachable = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > max_reachable)
                return false;
            max_reachable = max(max_reachable, i + nums[i]);
        }
        return true;
    }
};