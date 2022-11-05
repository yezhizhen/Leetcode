// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <string>
#include <unordered_map>

using namespace std;

class Trie
{
    bool is_full_word{false};
    unordered_map<char, Trie *> children;

public:
    void insert(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            if (!node->children.count(c))
                node->children[c] = new Trie();
            node = node->children[c];
        }
        node->is_full_word = true;
    }

    bool search(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            if (!node->children.count(c))
                return false;
            node = node->children[c];
        }
        return node->is_full_word;
    }

    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (char c : prefix)
        {
            if (!node->children.count(c))
                return false;
            node = node->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */