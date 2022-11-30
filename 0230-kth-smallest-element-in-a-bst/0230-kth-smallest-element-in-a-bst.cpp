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
    int counter = 0;
    void inorder(TreeNode* root, int k, int& ans){
        if(!root) return;
        
        inorder(root->left, k, ans);
        if(++counter == k){
            ans = root->val;
            return;
        }
        inorder(root->right, k, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder(root,k,ans);
        return ans;
    }
};