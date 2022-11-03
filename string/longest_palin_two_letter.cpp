// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> cnt;
        for (string &s : words)
            cnt[s]++;
        int ans = 0;
        bool exist_odd = false;

        for (auto &[s, frequency] : cnt)
        {
            if (frequency == 0)
                continue;

            if (s[0] == s[1])
            {
                if (frequency % 2 == 1)
                    exist_odd = true;
                ans += frequency / 2;
                continue;
            }

            auto it = cnt.find({s[1], s[0]});
            if (it != cnt.end())
            {
                int used = min(it->second, frequency);
                frequency -= used, it->second -= used;
                ans += used;
            }
        }
        return ans * 4 + exist_odd * 2;
    }
};