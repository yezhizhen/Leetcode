//https://leetcode.com/problems/longest-valid-parentheses/
//scan left and right
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int start = 0;
        while(start < s.size()){
            while(start < s.size() and s[start] == ')') start++;
            //found first '('
            int cur_valid_len = 0, unmatched_left = 0;
            for(;start < s.size();start++)
            {
                if(s[start] == '(') unmatched_left++;
                else{//')'
                    if(unmatched_left == 0)
                        break;
                    else{
                        cur_valid_len += 2, unmatched_left--;
                        if(unmatched_left == 0)
                            ans = max(ans, cur_valid_len);
                    }
                }
            }
        }
        start = int(s.size()) - 1;
        while(start >= 0){
            while(start >= 0 and  s[start] == '(') start--;
            //found first ')'
            int cur_valid_len = 0, unmatched_right = 0;
            for(;start >= 0; start--)
            {
                if(s[start] == ')') unmatched_right++;
                else{//'('
                    if(unmatched_right == 0)
                        break;
                    else{
                        cur_valid_len += 2, unmatched_right--;
                        if(unmatched_right == 0)
                            ans = max(ans, cur_valid_len);
                    }
                }
            }
        }
        
        return ans;
    }
};