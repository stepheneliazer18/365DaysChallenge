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
    TreeNode* helper(TreeNode* root){
        if(!root->left){
            return root->right;
        }
        TreeNode* prev = root->left;
        TreeNode* rightPart = root->right;
        while(prev->right) prev = prev->right;
        prev->right = rightPart;
        return root->left;
    }
    void deleteHelp(TreeNode* root, int key){
        if(!root) return;
        
        if(key < root->val) {
            if(root->left && root->left->val == key){
                root->left = helper(root->left);
                return;
            }
            deleteHelp(root->left, key);
        }
        else {
            if(root->right && root->right->val == key){
                root->right = helper(root->right);
                return;
            }
            deleteHelp(root->right, key);
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root && root->val == key){
            return helper(root);
        }
        deleteHelp(root,key);
        return root;
    }
};