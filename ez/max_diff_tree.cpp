#include <cstdlib>
#include <algorithm>
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
    int ans{0};

public:
    int maxAncestorDiff(TreeNode *root)
    {
        preorder(root, root->val, root->val);
        return ans;
    }

    void preorder(TreeNode *root, int min_val, int max_val)
    {
        if (!root)
            return;
        ans = max({ans, abs(min_val - root->val), abs(max_val - root->val)});
        preorder(root->left, min(min_val, root->val), max(max_val, root->val));
        preorder(root->right, min(min_val, root->val), max(max_val, root->val));
    }
};