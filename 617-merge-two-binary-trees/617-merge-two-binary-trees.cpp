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
    void help(TreeNode* root,TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return;
        if(root1 && root2) root->val = root1->val + root2->val;
        else if(root1) root->val = root1->val;
        else if(root2) root->val = root2->val;
        
        if(root1 && root1->left || root2 && root2->left){
            root->left = new TreeNode();
            if(root1 && root1->left && root2 && root2->left)
                help(root->left,root1->left,root2->left);
            else if(root1 && root1->left)
                help(root->left,root1->left,NULL);
            else if(root2 && root2->left)
                help(root->left,NULL,root2->left);
        }
        if(root1 && root1->right || root2 &&  root2->right){
            root->right = new TreeNode();
            if(root1 && root1->right && root2 && root2->right)
                help(root->right,root1->right,root2->right);
            else if(root1 && root1->right)
                help(root->right,root1->right,NULL);
            else if(root2 && root2->right)
                help(root->right,NULL,root2->right);
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;
        TreeNode* root = new TreeNode();
        help(root,root1,root2);
        return root;
    }
};