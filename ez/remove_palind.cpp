//https://leetcode.com/problems/remove-palindromic-subsequences/
class Solution {
    bool ispalind(string &s){
        int l = 0, r = s.size() - 1;
        
        while(l <= r and s[l] == s[r])
            l++, r--;
        if(l > r)
            return true;
        else
            return false;
    }
    
public:
    int removePalindromeSub(string &s) {
        return ispalind(s) ? 1 : 2;
    }
};