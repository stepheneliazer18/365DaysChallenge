class Solution {
public:
    vector<int> res;
    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return res[k-1];
    }
};