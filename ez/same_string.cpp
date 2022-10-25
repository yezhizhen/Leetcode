// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    // O(n+m) time O(1) space
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        // two pointers
        int ind1 = 0, ind2 = 0, w1_ind = 0, w2_ind = 0;
        while (ind1 < word1.size() && ind2 < word2.size())
        {
            if (word1[ind1][w1_ind++] != word2[ind2][w2_ind++])
                return false;
            if (w1_ind >= word1[ind1].length())
                ind1++, w1_ind = 0;
            if (w2_ind >= word2[ind2].length())
                ind2++, w2_ind = 0;
        }
        if (ind1 == word1.size() && ind2 == word2.size())
            return true;
        // not even same length
        return false;
    }
};