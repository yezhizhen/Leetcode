// https://leetcode.com/problems/break-a-palindrome/
#include <string>
using namespace std;

class Solution
{
public:
    string breakPalindrome(string &palindrome)
    {
        if (palindrome.length() == 1)
            return "";
        // scan from left to right. replace first
        for (int i = 0; i < palindrome.length() / 2; i++)
        {
            if (palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        // everything is 'a'
        palindrome.back() = 'b';
        return palindrome;
    }
};