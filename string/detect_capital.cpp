// https://leetcode.com/problems/detect-capital/

#include <string>
#include <cctype>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        // count capital
        int capital_cnt = 0;

        for (char c : word)
            if (isupper(c))
                capital_cnt++;

        if (capital_cnt == word.size() || capital_cnt == 0 || (capital_cnt == 1 && isupper(word[0])))
            return true;
        return false;
    }
};