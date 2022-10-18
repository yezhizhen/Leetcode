// https://leetcode.com/problems/count-and-say/
#include <string>
using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string prev = countAndSay(n - 1);
        int count = 1;
        string res;
        for (int i = 1; i < prev.size(); i++)
        {
            if (prev[i] == prev[i - 1])
                count++;
            else
            {
                res += to_string(count) + prev[i - 1];
                count = 1;
            }
        }
        // deal with final character
        res += to_string(count) + prev.back();
        return res;
    }
};