// https://leetcode.com/problems/longest-happy-prefix/description/
#include <string>
#include <vector>
using namespace std;

class Solution
{
    vector<int> next;

public:
    string longestPrefix(string s)
    {
        int n = s.size();
        next = vector<int>(n);
        // next[i] is the largest k (which is length) s.t. s[0..k-1] is same as s[i-k+1..i]
        //  but k cannot be i + 1
        // pre_compute next

        for (int i = 1; i < n; i++)
        {
            int now = next[i - 1];
            while (s[i] != s[now] && now > 0)
                now = next[now - 1];
            if (s[i] == s[now])
                next[i] = 1 + now;
        }
        return s.substr(0, next[n - 1]);
    }
};
// explanation
// https://www.zhihu.com/question/21923021
