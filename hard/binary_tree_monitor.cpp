//https://leetcode.com/problems/binary-tree-cameras/
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
    int ans = 0;
public:
    int minCameraCover(TreeNode* root) {
        return post_order(root) ? ans : ++ans;
        
    }
    
    //true if the node is monitored
    bool post_order(TreeNode* root){
        if(not root) return true;
        bool l = post_order(root->left), r = post_order(root->right);
        //both child monitored. don't put camera at root.
        if(l and r)
            return false;
        else{
            ans++;
            return true;
        }
    }
};