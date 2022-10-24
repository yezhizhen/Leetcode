// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

#include <vector>
#include <string>
using namespace std;
// 100% time 100% memory
class Solution
{
    int max_len = 0;
    int cur_len = 0;
    int bitmask = 0;
    vector<int> masks_for_string; // the occurence mask for each string in deduplicated arr

public:
    int maxLength(vector<string> &arr)
    {
        vector<string> deduplicated_arr;
        // remove all those contain duplicate
        for (string &s : arr)
        {
            bool occ[26]{};
            bool remove = false;
            for (char &c : s)
                if (occ[c - 'a'])
                {
                    remove = true;
                    break;
                }
                else
                    occ[c - 'a'] = true;
            if (!remove)
                deduplicated_arr.push_back(move(s));
        }
        arr = move(deduplicated_arr);
        masks_for_string.reserve(arr.size());
        for (const string &s : arr)
        {
            int cur = 0;
            for (const char &c : s)
                cur |= 1 << (c - 'a');
            masks_for_string.push_back(cur);
        }
        solve(arr, 0);
        return max_len;
    }

    void solve(vector<string> &arr, int start)
    {
        if (start == arr.size())
            return;
        // don't include start
        solve(arr, start + 1);
        // include start
        // only when unique
        if ((bitmask & masks_for_string[start]) == 0)
        {
            bitmask |= masks_for_string[start];
            cur_len += arr[start].length();
            if (cur_len > max_len)
                max_len = cur_len;
            solve(arr, start + 1);
            cur_len -= arr[start].length();
            // restore
            bitmask ^= masks_for_string[start];
        }
    }
};