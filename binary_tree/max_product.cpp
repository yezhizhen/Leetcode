// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
#include <algorithm>
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
    int sum{0};
    long ans{0};
    const int mod = 1e9 + 7;

public:
    int maxProduct(TreeNode *root)
    {
        compute_sum(root);
        solve(root);
        return ans % mod;
    }

    // compute the sum of subtree at root
    int solve(TreeNode *root)
    {
        if (!root)
            return 0;
        long subtree_sum = root->val + solve(root->left) + solve(root->right);
        ans = std::max(ans, (sum - subtree_sum) * subtree_sum);
        return subtree_sum;
    }

    void compute_sum(TreeNode *root)
    {
        if (!root)
            return;
        sum += root->val;
        compute_sum(root->left);
        compute_sum(root->right);
    }
};