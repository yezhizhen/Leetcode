/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return getSubtree(root, val, depth, true);
    }

    TreeNode* getSubtree(TreeNode* root, int val, int depth, bool from_left) {
        //create new nodes at this layer
        if (depth == 1)
            return from_left ? new TreeNode(val, root, nullptr) : new TreeNode(val, nullptr, root);
        //pre-order search
        if(!root)
            return nullptr;
        root->left = getSubtree(root->left, val, depth - 1, true);
        root->right = getSubtree(root->right, val, depth - 1, false);

        return root;
    }

};