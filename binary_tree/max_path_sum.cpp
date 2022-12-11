#include <algorithm>
using std::max;
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
    int ans{-1001};

public:
    int maxPathSum(TreeNode *root)
    {
        max_downright_sum_at_root(root);
        return ans;
    }

    int max_downright_sum_at_root(TreeNode *root)
    {
        if (!root)
            return 0;
        int left_res = max(0, max_downright_sum_at_root(root->left));
        int right_res = max(0, max_downright_sum_at_root(root->right));
        ans = max(ans, root->val + left_res + right_res);
        return root->val + max(left_res, right_res);
    }
};