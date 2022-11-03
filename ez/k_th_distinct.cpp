// https://leetcode.com/problems/kth-distinct-string-in-an-array/

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_set<string> visited;
        unordered_set<string> duplicate_str;
        for (int i = 0; i < arr.size(); i++)
        {
            if (visited.count(arr[i]))
                duplicate_str.insert(arr[i]);
            else
                visited.insert(arr[i]);
        }
        int distinct_count = 0;
        for (const string &s : arr)
        {
            // is distinct
            if (!duplicate_str.count(s))
                if (++distinct_count == k)
                    return s;
        }
        return "";
    }
};