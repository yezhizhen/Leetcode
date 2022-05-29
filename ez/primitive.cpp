class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken[26]{};
        for(char c: brokenLetters)
                broken[c-'a'] = true;
        int ans = 0; bool good_word= true;
        for(char c: text)
        {
            if(c == ' '){
                if(good_word)   ans++;
                good_word = true;
            }
            else{
                if(broken[c - 'a']) good_word = false;
            }
        }
        if(good_word)
            ans++;
        return ans;
    }
};