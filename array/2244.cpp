// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {

        int i = 0, n = tasks.size();
        sort(tasks.begin(), tasks.end());
        int steps = 0;
        while (i < n)
        {
            i++;
            int cnt = 1;
            // count the consecutive block size
            while (i < n && tasks[i] == tasks[i - 1])
                cnt++, i++;
            if (cnt == 1)
                return -1;
            int mod = cnt % 3;
            if (mod == 0)
                steps += cnt / 3;
            else
                steps += cnt / 3 + 1;
        }
        return steps;
    }
};