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
    bool ans = true;
private:
    int height(TreeNode* root){
        if(!root) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
                
        return 1 + max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        if(abs(leftHeight - rightHeight) > 1) return false;
        
        bool leftCheck = isBalanced(root->left);
        bool rightCheck = isBalanced(root->right);
        
        return leftCheck && rightCheck;
    }
};