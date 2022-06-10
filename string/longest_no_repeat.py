#https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l, ans  = 0, 0
        cnt_map = {}
        #try include s[r]
        for r in range(len(s)):
            #check conflict
            if s[r] in cnt_map:
                cnt_map[s[r]] += 1
                while cnt_map[s[r]] > 1:
                    cnt_map[s[l]] -= 1
                    l += 1
                #no conflict in l..r now    
            else:
                cnt_map[s[r]] = 1
            
            ans = max(ans, r - l + 1)
        return ans
        