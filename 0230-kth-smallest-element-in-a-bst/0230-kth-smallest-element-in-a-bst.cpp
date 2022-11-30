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
    int inorder(TreeNode* root, int k){
        if(!root) return -1;
        
        int l = inorder(root->left, k);
        counter++;
        if(counter == k) return root->val;
        int r = inorder(root->right, k);
        if(l == -1) return r;
        return l;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root,k);
    }
};