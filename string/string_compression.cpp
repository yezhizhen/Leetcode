#include <vector>
#include <string>
using std::to_string;
using std::vector;
// https://leetcode.com/problems/string-compression/
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        if (chars.size() == 1)
            return 1;

        int write_index = 0, count = 1;
        for (int i = 1; i < chars.size(); i++)
        {
            if (chars[i] == chars[i - 1])
            {
                count++;
            }
            else
            {
                chars[write_index++] = chars[i - 1];
                // write numbers
                if (count == 1)
                    continue;
                else
                {
                    for (char c : to_string(count))
                        chars[write_index++] = c;
                }
                count = 1;
            }
        }
        // deal with last character
        chars[write_index++] = chars.back();
        if (count > 1)
        {
            for (char c : to_string(count))
                chars[write_index++] = c;
        }
        return write_index;
    }
};