#https://leetcode.com/problems/remove-palindromic-subsequences/
class Solution:
    def removePalindromeSub(self, s: str) -> int:
        return 1 if s == s[::-1] else 2 #check if same as reversed