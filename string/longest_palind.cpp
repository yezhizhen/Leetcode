//https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/discuss/1994501/C%2B%2B-oror-O(n)-space-oror-O(n)-time
int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> cnt;
        for(const string& s: words)
            cnt[s]++;
        int len{0};
        bool appeared{false}; //whether there is an odd # of "aa" used
        for(const auto &[s,occ]: cnt)
        {
            if(s[1] == s[0])
            {
                if(not appeared and occ % 2 == 1) //use odd
                {
                    appeared = true; 
                    len += occ;
                    continue;
                }
                len += occ / 2 * 2;//use even number of them
            }
            else{
                auto it = cnt.find({s[1],s[0]});
                if(it != cnt.end())
                    len+= min(it->second, occ); // just add itself. the counterpart is responsible for itself too.
            }
        }
        return 2 * len;
    }