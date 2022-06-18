//https://leetcode.com/problems/prefix-and-suffix-search/

//can use a Trie to reduce space. Right now each string occupies 1 + 2 + 3 + ... + L = O(L^2) space

class WordFilter {
    unordered_map<string,vector<int>> prefix_to_inds; //each vector in increasing order
    unordered_map<string,unordered_set<int>> reversed_suffix_to_inds;
    
public:
    WordFilter(vector<string>& words) {
        for(int j = 0; j < words.size(); j++){
            //from front to end
            string &s = words[j]; //j-th word
            string pre, suf; pre.reserve(s.size()); suf.reserve(s.size());
            for(int i = 0; i < s.size(); i++){
                pre += s[i];
                suf += s[s.size() - 1 - i];
                prefix_to_inds[pre].push_back(j);
                reversed_suffix_to_inds[suf].insert(j);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        vector<int> &pre_inds = prefix_to_inds[prefix];
        reverse(suffix.begin(), suffix.end());
        unordered_set<int> &suf_inds = reversed_suffix_to_inds[suffix];
        
        if(suf_inds.empty())
            return -1;
        for(auto it = pre_inds.rbegin(); it != pre_inds.rend(); it++)
            if(suf_inds.count(*it))
                return *it;
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */