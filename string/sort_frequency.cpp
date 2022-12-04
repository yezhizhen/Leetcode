#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> cnt;
        for (char c : s)
            cnt[c]++;
        vector<pair<int, char>> v;
        for (auto &[ch, occ] : cnt)
            v.emplace_back(occ, ch);
        sort(v.begin(), v.end(), [](auto &p1, auto &p2)
             { return p1.first > p2.first; });
        string res;
        res.reserve(s.size());
        for (auto &[occ, ch] : v)
            res += string(occ, ch);
        return res;
    }
};