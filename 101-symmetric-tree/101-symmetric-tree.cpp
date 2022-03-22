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
    
    bool inorder(TreeNode* l, TreeNode* r){
        if(!r && !l) return true;
        if(!r) return false;
        if(!l) return false;
        
        if(r->val != l->val) return false;
        
        bool le = inorder(l->left,r->right);
        bool re = inorder(r->left,l->right);
        
        return le && re;
        
    }
    
    bool isSymmetric(TreeNode* root) {
        return inorder(root->left, root->right);
    }
};