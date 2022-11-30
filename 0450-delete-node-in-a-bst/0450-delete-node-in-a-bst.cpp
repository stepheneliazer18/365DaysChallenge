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
    void helper(TreeNode* root){
        if(!root->left){
            root->left = root->right;
            return;
        }
        TreeNode* prev = root->left;
        TreeNode* rightPart = root->right;
        while(prev && prev->right) prev = prev->right;
        if(prev) prev->right = rightPart;
    }
    void deleteHelp(TreeNode* root, int key){
        if(!root) return;
        
        if(key < root->val) {
            if(root->left && root->left->val == key){
                helper(root->left);
                root->left = root->left->left;
                return;
            }
            deleteHelp(root->left, key);
        }
        else {
            if(root->right && root->right->val == key){
                helper(root->right);
                root->right = root->right->left;
                return;
            }
            deleteHelp(root->right, key);
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root && root->val == key){
            if(root->left){
                helper(root);
                root = root->left;
            }
            else root = root->right;
            return root;
        }
        deleteHelp(root,key);
        return root;
    }
};