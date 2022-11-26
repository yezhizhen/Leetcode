#include <vector>
#include <algorithm>
using namespace std;

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = profit.size();
        vector<int> dp(n + 1); // dp[i]: first i items best result

        // sort by endtime
        vector<int> index_by_end(n);
        for (int i = 0; i < n; i++)
            index_by_end[i] = i;

        sort(index_by_end.begin(), index_by_end.end(), [&](int &i, int &j)
             { return endTime[i] < endTime[j]; });
        dp[1] = profit[index_by_end[0]];
        for (int i = 1; i < n; i++)
        {
            int cur_index = index_by_end[i];
            // check conflict
            if (startTime[cur_index] >= endTime[index_by_end[i - 1]])
            {
                dp[i + 1] = profit[cur_index] + dp[i];
            }
            else
            {
                // find first x where end_time[x] > start_time[cur_index]
                int left = 0, right = i - 1;
                int x = upper_bound(index_by_end.begin(), index_by_end.begin() + i - 1, startTime[cur_index],
                                    [&](int &start_t, int &ind)
                                    { return start_t < endTime[ind]; }) -
                        index_by_end.begin();
                dp[i + 1] = max(dp[x] + profit[cur_index], dp[i]);
            }
        }
        return dp[n];
    }
};

// without STL

class Solution
{
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = profit.size();
        vector<int> dp(n + 1); // dp[i]: first i items best result

        // sort by endtime
        vector<int> index_by_end(n);
        for (int i = 0; i < n; i++)
            index_by_end[i] = i;

        sort(index_by_end.begin(), index_by_end.end(), [&](int &i, int &j)
             { return endTime[i] < endTime[j]; });
        dp[1] = profit[index_by_end[0]];
        for (int i = 1; i < n; i++)
        {
            int cur_index = index_by_end[i];
            // check conflict
            if (startTime[cur_index] >= endTime[index_by_end[i - 1]])
            {
                dp[i + 1] = profit[cur_index] + dp[i];
            }
            else
            {
                // find k where [0..k] does not conflict but [0..k + 1 conflict]
                int left = 0, right = i - 1;
                while (left <= right)
                {
                    int k = (left + right) / 2;
                    if (endTime[index_by_end[k]] <= startTime[cur_index] && endTime[index_by_end[k + 1]] > startTime[cur_index])
                    {
                        dp[i + 1] = dp[k + 1] + profit[cur_index];

                        break;
                    }
                    // still conflict
                    if (endTime[index_by_end[k]] > startTime[cur_index])
                        right = k - 1;
                    else
                        left = k + 1;
                }
                dp[i + 1] = max({dp[i + 1], dp[i], profit[cur_index]});
            }
        }
        return dp[n];
    }
};