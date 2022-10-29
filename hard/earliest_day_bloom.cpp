// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    // notice that, the result would be
    //  total plant time + grow time of last item, or the previous one
    //  By swapping argument, it is always better
    //  to plant the one with small grow time later
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        using mP = pair<int, int>;
        vector<mP> grow_plant;
        int n = plantTime.size();
        grow_plant.reserve(n);
        for (int i = 0; i < n; i++)
            grow_plant.emplace_back(move(growTime[i]), move(plantTime[i]));
        sort(grow_plant.begin(), grow_plant.end(), greater<mP>());
        int ans = 0;
        int cur_t = 0;
        for (int i = 0; i < n; i++)
            cur_t += grow_plant[i].second, ans = max(ans, cur_t + grow_plant[i].first);
        return ans;
    }
};