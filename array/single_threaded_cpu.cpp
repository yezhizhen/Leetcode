#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {

        int n = tasks.size();
        vector<int> indices(n);
        for (int i = 0; i < n; i++)
            indices[i] = i;
        // sort by enquetime
        sort(indices.begin(), indices.end(), [&](auto &t1, auto &t2)
             { return tasks[t1][0] < tasks[t2][0]; });

        // true if ind2 extracted first
        auto cmp = [&](int &ind1, int &ind2)
        {
            if (tasks[ind2][1] < tasks[ind1][1])
                return true;
            else if (tasks[ind2][1] > tasks[ind1][1])
                return false;
            else
                return ind2 < ind1;
        };

        // queue of event that is processable
        priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
        vector<int> ans;
        ans.reserve(n);
        // current time
        int t = tasks[indices[0]][0];
        for (int i = 0; i < n; i++)
        {
            // deal with all the event in the queue, until indices[i] processable
            while (t < tasks[indices[i]][0] && !q.empty())
            {
                t += tasks[q.top()][1];
                ans.push_back(q.top());
                q.pop();
            }
            if (t < tasks[indices[i]][0])
                t = tasks[indices[i]][0];
            q.push(indices[i]);
        }
        // t has been large enough to schedule all tasks
        while (!q.empty())
        {
            // t += tasks[indices[q.top()]][1];
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};