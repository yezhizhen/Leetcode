#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        sort(costs.begin(), costs.end());
        int cnt = 0;
        for (int cost : costs)
            if (coins >= cost)
                cnt++, coins -= cost;
            else
                break;
        return cnt;
    }

    // count sort
    int maxIceCream(vector<int> &costs, int coins)
    {
        int n = costs.size();
        int m = *max_element(costs.begin(), costs.end());
        int icecreams = 0;

        vector<int> costsFrequency(m + 1);
        for (auto &cost : costs)
        {
            costsFrequency[cost]++;
        }

        for (int cost = 1; cost <= m; ++cost)
        {

            if (costsFrequency[cost] == 0)
            {
                continue;
            }

            int count = min(costsFrequency[cost], coins / cost);

            // We reduce price of picked ice creams from our coins.
            coins -= cost * count;
            icecreams += count;
            if (count < costsFrequency[cost])
                break;
        }

        return icecreams;
    }
};