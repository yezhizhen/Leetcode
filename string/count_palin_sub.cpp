//https://leetcode.com/problems/palindromic-substrings/
//https://leetcode.com/problems/palindromic-substrings/discuss/2061664/C%2B%2B-oror-100-runtime
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int center = 0; center < s.size();){
            int r = center; //count same character
            while(r < s.size() and s[r] == s[center])
                r++;
            int len = r - center; ans += len * (len + 1) / 2; //number of palindrome for "aaaa", len = 4
            int l = center - 1; center = r; //r would be the next center
            while( l >= 0 and r < s.size() and s[l] == s[r])
                l--, r++, ans++;
        }
        return ans;
    }
};