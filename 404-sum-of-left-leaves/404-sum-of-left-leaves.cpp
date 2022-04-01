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
    int sum = 0;
    void help(TreeNode* root){
        if(!root) return;
        if(root->left && root->left->left == NULL && root->left->right==NULL){
             cout<<root->val<<endl;
             sum+=root->left->val;
        }
        
        help(root->left);
        help(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        help(root);
        return sum;
    }
};