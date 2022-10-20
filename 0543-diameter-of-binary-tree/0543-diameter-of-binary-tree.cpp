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
private:
    int height(TreeNode* root){
        if(!root) return 0;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return 1 + max(left,right);
    }
    

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        int diameter = lh + rh;
        
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        
        int maxi = max(leftDiameter,rightDiameter);
        return max(maxi,diameter);
    }
};