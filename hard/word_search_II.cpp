#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution
{
    struct Trie
    {
        unordered_map<char, Trie *> children;
        string word;

        void insert(string word)
        {
            Trie *node = this;
            for (char c : word)
            {
                if (!node->children.count(c))
                    node->children[c] = new Trie();
                node = node->children[c];
            }
            node->word = word;
        }
    };

    vector<string> res;
    int dirs[4][2]{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int m, n;

public:
    void dfs(vector<vector<char>> &board, int x, int y, Trie *cur_node)
    {
        // if full word
        if (cur_node->word.size())
            res.push_back(cur_node->word), cur_node->word = "";
        char tmp = board[x][y];
        board[x][y] = '#';
        // check neighbor
        for (auto &direction : dirs)
        {
            int nx = x + direction[0], ny = y + direction[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] != '#')
            {
                if (cur_node->children.count(board[nx][ny]))
                    dfs(board, nx, ny, cur_node->children[board[nx][ny]]);
            }
        }
        board[x][y] = tmp;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        m = board.size(), n = board[0].size();
        Trie trie;
        for (string &s : words)
            trie.insert(s);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (trie.children.count(board[i][j]))
                    dfs(board, i, j, trie.children[board[i][j]]);
            }

        return res;
    }
};