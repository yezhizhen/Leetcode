#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> leaves;
    bool similar = true;
    int ind = 0;
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        fill(root1);
        check(root2);
        return similar && ind == leaves.size();
    }

    void check(TreeNode *root)
    {
        if (!root)
            return;
        if (ind >= leaves.size())
            similar = false;
        if (!similar)
            return;
        // leaves
        if (!root->left && !root->right)
        {
            if (root->val != leaves[ind++])
                similar = false;
            return;
        }
        check(root->left);
        check(root->right);
    }

    void fill(TreeNode *root)
    {
        if (!root)
            return;
        // leaves
        if (!root->left && !root->right)
        {
            leaves.push_back(root->val);
            return;
        }
        fill(root->left);
        fill(root->right);
    }
};