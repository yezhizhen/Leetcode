//https://leetcode.com/problems/search-suggestions-system/


//brute force. with move operations
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord){
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        
        vector<string> potential = move(products);
        vector<string> tmp; 
        for(int i = 0; i < searchWord.size(); i++){
            char c = searchWord[i];
            for(string &s:potential)
                if(i < s.size() and s[i] == c)
                    tmp.push_back(move(s));
            if(tmp.size() <= 3)
                ans.push_back(tmp);
            else
                ans.push_back({tmp[0], tmp[1], tmp[2]});
            potential = tmp;
            tmp.clear();
        }
        return ans;
    }
};


//binary search//store potential result after each round

class BSSolution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord){
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        
        vector<string> potential = move(products);
        vector<string> tmp;
        for(int i = 0; i < searchWord.size(); i++){
            char c = searchWord[i];
            //binary search within potential
            int start = lower_bound(potential.begin(), potential.end(), c, 
                [&i](const string &s,const char current_c)
                {
                    //first false to be found
                    return i < s.size() ? s[i] < current_c: true;
                }) - potential.begin();
            //fill the tmp
            for(; start < potential.size() and i < potential[start].size() 
                and potential[start][i] == c
                ; start++)
                tmp.push_back(move(potential[start]));
            
            if(tmp.size() <= 3)
                ans.push_back(tmp);
            else
                ans.push_back({tmp[0], tmp[1], tmp[2]});
            potential = tmp;
            tmp.clear();
        }
        return ans;
    }
};



class OfficialSolution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products,
                                             string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result;
        int start, bsStart = 0, n=products.size();
        string prefix;
        for (char &c : searchWord) {
            prefix += c;

            // Get the starting index of word starting with `prefix`.
            start = lower_bound(products.begin() + bsStart, products.end(), prefix) - products.begin();

            // Add empty vector to result.
            result.push_back({});

            // Add the words with the same prefix to the result.
            // Loop runs until `i` reaches the end of input or 3 times or till the
            // prefix is same for `products[i]` Whichever comes first.
            for (int i = start; i < min(start + 3, n) && !products[i].compare(0, prefix.length(), prefix); i++)
                result.back().push_back(products[i]);

            // Reduce the size of elements to binary search on since we know
            bsStart = start;
        }
        return result;
    }
};



// Custom class Trie with function to get 3 words starting with given prefix
class Trie
{
    // Node definition of a trie
    struct Node {
        bool isWord = false;
        vector<Node *> children{vector<Node *>(26, NULL)};
    } * Root, *curr;

    // Runs a DFS on trie starting with given prefix and adds all the words in the result, limiting result size to 3
    void dfsWithPrefix(Node * curr, string & word, vector<string> & result) {
        if (result.size() == 3)
            return;
        if (curr->isWord)
            result.push_back(word);

        // Run DFS on all possible paths.
        for (char c = 'a'; c <= 'z'; c++)
            if (curr->children[c - 'a']) {
                word += c;
                dfsWithPrefix(curr->children[c - 'a'], word, result);
                word.pop_back();
            }
    }

public:
    Trie() {
        Root = new Node();
    }
    // Inserts the string in trie.
    void insert(string & s) {
        // Points curr to the root of trie.
        curr = Root;
        for (char &c : s) {
            if (!curr->children[c - 'a'])
                curr->children[c - 'a'] = new Node();
            curr = curr->children[c - 'a'];
        }
        // Mark this node as a completed word.
        curr->isWord = true;
    }
    vector<string> getWordsStartingWith(string & prefix) {
        curr = Root;
        vector<string> result;

        // Move curr to the end of prefix in its trie representation.
        for (char &c : prefix) {
            if (!curr->children[c - 'a'])
                return result;
            curr = curr->children[c - 'a'];
        }
        dfsWithPrefix(curr, prefix, result);
        return result;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string> &products,
                                             string searchWord) {
        Trie trie=Trie();
        vector<vector<string>> result;

        // Add all words to trie.
        for(string &w:products)
            trie.insert(w);
        string prefix;
        for (char &c : searchWord) {
            prefix += c;
            result.push_back(trie.getWordsStartingWith(prefix));
        }
        return result;
    }
};