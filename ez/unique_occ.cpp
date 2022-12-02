// https://leetcode.com/problems/unique-number-of-occurrences/

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> occ;
        for (int num : arr)
            occ[num]++;
        unordered_set<int> unique_check;
        for (auto &[_, cnt] : occ)
        {
            if (unique_check.count(cnt))
                return false;
            unique_check.insert(cnt);
        }
        return true;
    }
};