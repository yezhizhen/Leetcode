//https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
class Solution {
    unordered_map<int, int> cnt; //occurence 
    int ans = 0;
    
    bool ispseudo(){
        //check if only one odd within cnt
        bool has_odd{};
        for(auto &[val, occ]: cnt){
            if(occ % 2 == 1)
            {
                if(has_odd)
                    return false;
                has_odd = true;
            }
        }
        return true;
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        //do a preorder traversal(DFS)
        dfs(root);
        return ans;
    }
    
    //assumption: root never nullptr
    void dfs(TreeNode* root){
        cnt[root->val]++;
        
        if(root->left)
            dfs(root->left);
        if(root->right)
            dfs(root->right);
        //leaf node
        if(not root->left and not root->right)
            ans += ispseudo();
        
        cnt[root->val]--;
    }
    
};