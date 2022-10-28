
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> sorted_str_to_group;
        vector<vector<string>> res;
        for (string &s : strs)
        {
            string s_copy = s;
            sort(s_copy.begin(), s_copy.end());
            sorted_str_to_group[s_copy].push_back(move(s));
        }
        for (auto &[_, groups] : sorted_str_to_group)
            res.push_back(move(groups));
        return res;
    }
};