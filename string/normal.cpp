//https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
class Solution {
    
    bool issub(string &longer, string &shorter){
        if(longer.size() < shorter.size()) return false;
        int l = 0, r = 0;
        
        while(l < longer.size() and r < shorter.size()){
            if(longer[l] != shorter[r])
                l++;
            else
                l++, r++;
        }
        if(r == shorter.size())
            return true;
        return false;
    }
    
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        //test if a string is a subsequence
        int ans_ind{-1};
        
        for(int i = 0; i < dictionary.size(); i++ )
        {
            string &word = dictionary[i];
            if(issub(s, word))
            {
                if(ans_ind == -1)
                {
                    ans_ind = i;
                }
                else{
                    string &old_ans = dictionary[ans_ind];
                    //require longest word
                    if(word.size() > old_ans.size())
                        ans_ind = i;
                    else if(word.size() == old_ans.size()){
                        //least lex
                        if(word < old_ans){
                            ans_ind = i;
                        }
                    }
                }
            }
                
        }
        return ans_ind == -1? "" : dictionary[ans_ind];
        
    }
};