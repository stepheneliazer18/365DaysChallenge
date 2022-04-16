class Solution {
public:
    int value = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL) return NULL;
        
        TreeNode* right = convertBST(root->right);
        
        value = value +root->val;
        
        root->val = value;
        
        TreeNode* left = convertBST(root->left);
        
        return root;
    }
};