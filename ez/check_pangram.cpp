#include <string>
using namespace std;
// https://leetcode.com/problems/check-if-the-sentence-is-pangram/
class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        bool occ[26]{};
        int remain = 26;
        for (const char &c : sentence)
        {
            if (!occ[c - 'a'])
            {
                occ[c - 'a'] = true;
                remain--;
                if (remain == 0)
                    return true;
            }
        }
        return false;
    }
};