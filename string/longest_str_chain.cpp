//https://leetcode.com/problems/longest-string-chain/discuss/?currentPage=1&orderBy=hot&query=
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](auto &s1, auto &s2){
            return s1.size() < s2.size();});
        vector<int> ind_to_chain_len(words.size(), 1);
        
        for(int i = 1; i < words.size(); i++){
            string &cur = words[i];
            int pre = i - 1;
            for(; pre >= 0 and words[pre].size() == cur.size(); pre--);
            
            //can be possibily chained. with length difference 1
            for(; pre >= 0 and words[pre].size() == cur.size() - 1; pre--)
                if(chainable(words[pre], cur))
                    ind_to_chain_len[i] = max(ind_to_chain_len[i], ind_to_chain_len[pre] + 1);
        }
        return *max_element(ind_to_chain_len.begin(), ind_to_chain_len.end());
    }
    
    bool chainable(string &pre, string &cur){
        //find first missing
        int i = 0;
        for(; i < pre.size() and pre[i] == cur[i]; i++);
        //now, pre[i] and cur[i+1] should be same
        for(; i < pre.size() and pre[i] == cur[i+1];i++);
        
        return i == pre.size() ? true : false;
    }
};  