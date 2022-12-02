// https://leetcode.com/problems/determine-if-two-strings-are-close/

#include <string>
#include <array>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size())
            return false;
        array<int, 26> cnt1{0};
        array<int, 26> cnt2{0};
        for (char c : word1)
            cnt1[c - 'a']++;
        for (char c : word2)
            cnt2[c - 'a']++;
        for (int i = 0; i < 26; i++)
            if ((cnt1[i] == 0 && cnt2[i] > 0) || (cnt1[i] > 0 && cnt2[i] == 0))
                return false;
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        return cnt1 == cnt2;
    }
};