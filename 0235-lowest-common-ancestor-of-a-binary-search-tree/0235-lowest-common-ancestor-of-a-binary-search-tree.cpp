/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        
        int n1 = p->val;
        int n2 = q->val;
        
        if(n1 < root->val && n2 < root->val) return lowestCommonAncestor(root->left, p, q);
        if(n1 > root->val && n2 > root->val) return lowestCommonAncestor(root->right, p , q);               return root;
    }
};