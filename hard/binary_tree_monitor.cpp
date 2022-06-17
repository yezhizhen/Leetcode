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
    
    //0 if not covered
    //1 if covered by child but no monitor
    //2 if has a monitor right on root
    int post_order(TreeNode* root){
        if(not root) return 1;
        int l = post_order(root->left), r = post_order(root->right);
        //have to put a monitor at root
        if(l == 0 or r == 0){
            ans++;
            return 2;
        }
        //current node already covered
        else if(l == 2 or r == 2)
            return 1;
        else //not covered. leave it to parent
            return 0;
    }
};