#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt = 0;
        for (int i = 0; i < s.size() / 2; i++)
            cnt += vowels.count(s[i]);

        for (int i = s.size() / 2; i < s.size(); i++)
            cnt -= vowels.count(s[i]);

        return cnt == 0;
    }
};