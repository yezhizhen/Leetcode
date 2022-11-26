// https://leetcode.com/problems/maximum-69-number/
#include <string>
using namespace std;
class Solution
{
public:
    int maximum69Number(int num)
    {
        // detect the position of most significant 6
        string s = to_string(num);
        for (char &c : s)
            if (c == '6')
            {
                c = '9';
                break;
            }
        return stoi(s);
    }
};