// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/
#include <string>
using std::max;
using std::string;
class Solution
{
public:
    // find longest substring aaa..bbb...
    int minimumDeletions(string s)
    {
        int n = s.size();
        int count_b = 0;
        for (int i = 0; i < n; i++)
            count_b += (s[i] == 'b');
        int cur_b = 0;
        // all "aaaa" or all
        int longest_ans = n - count_b;
        // the loop would miss out the case taking 0 b
        for (int i = 0; i < n; i++)
        {
            // let s[i] be the start of bbbb...
            if (s[i] == 'b')
            {
                longest_ans = max(longest_ans, count_b - cur_b + i - cur_b);
                cur_b++;
            }
        }
        return n - longest_ans;
    }
};