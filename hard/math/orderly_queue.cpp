#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        if (k == 1)
        {
            string ans = s;
            for (int break_point = 1; break_point < s.size(); break_point++)
                ans = min(ans, s.substr(break_point) + s.substr(0, break_point));
            return ans;
        }
        else
        {
            sort(s.begin(), s.end());
            return s;
        }
    }
};