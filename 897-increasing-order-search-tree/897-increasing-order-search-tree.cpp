class Solution {
public:
    TreeNode* res = new TreeNode(0);
    void help(TreeNode* root){
        if(!root) return ;

        help(root->left);

        root->left=NULL;
        
        res->right=root;
        
        res = root;
        
        help(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* finalres = res;
        help(root);
        
        return finalres->right;
    }
};