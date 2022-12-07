
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
    int ans{0};
    int low, high;
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        // in order search
        this->low = low, this->high = high;
        search(root);
        return ans;
    }

    void search(TreeNode *root)
    {
        if (!root)
            return;
        if (root->val < low)
            search(root->right);
        else if (root->val > high)
            search(root->left);
        else
        {
            ans += root->val;
            search(root->left);
            search(root->right);
        }
    }
};