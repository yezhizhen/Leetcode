// https://leetcode.com/problems/reverse-vowels-of-a-string/
#include <string>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    string reverseVowels(string s)
    {
        int n = s.size(), left = 0, right = n - 1;
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        // move left, right  to a vowel
        while (left < right)
        {
            while (left < right && !vowels.count(s[left]))
                left++;
            while (right > left && !vowels.count(s[right]))
                right--;
            if (left == right)
                break;
            // swap left, right
            swap(s[left++], s[right--]);
        }
        return s;
    }
};