//https://leetcode.com/problems/short-encoding-of-words/discuss/2172492/Trie-oror-C%2B%2B-oror-O(total-length)
struct TrieNode{
    TrieNode* children[26]{};
    int count{}; //how many active children
    
    TrieNode* get(char c){
        //already inserted
        if(children[c - 'a'])
            return children[c - 'a'];
        else{
            count++;
            return children[c - 'a'] = new TrieNode();
        }
    }
};


class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode *root = new TrieNode(); 
        unordered_map<TrieNode*, int> res; //from a word trie end node to the length of the word
        for(string &w: words){
            TrieNode *cur = root;
            //insert it into the Trie
            for(int i = w.size() - 1; i >= 0; i--)
                cur = cur->get(w[i]);
            if(cur->count == 0) res[cur] = w.size() + 1;
        }
        int ans = 0;
        for(const auto &[node, len]: res)
            if(node->count == 0) ans += len;
        return ans;
    }
};