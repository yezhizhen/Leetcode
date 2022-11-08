// https://leetcode.com/problems/make-the-string-great/

#include <string>
using namespace std;

class Solution
{
public:
    string makeGood(string s)
    {
        string ans = s.substr(0, 1);
        for (int i = 1; i < s.size(); i++)
        {
            if (ans.empty())
                ans += s[i];
            else
            {
                // check if collide
                if (abs(ans.back() - s[i]) == 32)
                    ans.pop_back();
                else
                    ans += s[i];
            }
        }
        return ans;
    }

    // O(1) space
    string makeGood(string s)
    {
        int last_index = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (last_index == -1)
                s[0] = s[i], last_index = 0;
            else
            {
                // check if collide
                if (abs(s[last_index] - s[i]) == 32)
                    last_index--;
                else
                    s[++last_index] = s[i];
            }
        }
        return s.substr(0, last_index + 1);
    }
};