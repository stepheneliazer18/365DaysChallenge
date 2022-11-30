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
    void deleteHelp(TreeNode* root, int key){
        if(!root) return;
        
        if(key < root->val) {
            if(root->left && root->left->val == key){
                if(!root->left->left){
                    root->left = root->left->right;
                    return;
                }
                TreeNode* rightPart = root->left->right;
                TreeNode* prev = root->left->left;
                while(prev->right) prev = prev->right;
                root->left = root->left->left;
                prev->right = rightPart;
                return;
            }
            deleteHelp(root->left, key);
        }
        else {
            if(root->right && root->right->val == key){
                if(!root->right->left){
                    root->right = root->right->right;
                    return;
                }
                TreeNode* rightPart = root->right->right;
                TreeNode* prev = root->right->left;
                while(prev->right) prev = prev->right;
                root->right = root->right->left;
                prev->right = rightPart;
                return;
            }
            deleteHelp(root->right, key);
        }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root && root->val == key){
            if(root->left){
                TreeNode* rightPart = root->right;
                TreeNode* prev = root->left;
                while(prev && prev->right) prev = prev->right;
                root = root->left;
                if(prev) prev->right = rightPart;
                return root;
            }
            root = root->right;
            return root;
        }
        deleteHelp(root,key);
        return root;
    }
};