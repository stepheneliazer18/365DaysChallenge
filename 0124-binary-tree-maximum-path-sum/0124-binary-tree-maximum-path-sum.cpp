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
    int sum(TreeNode* root){
        if(!root) return 0;
        
        int left = sum(root->left);
        int right = sum(root->right);
        
        int ans = root->val + max(left,right);
        return max(ans,0);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return INT_MIN;
        
        int ls = sum(root->left);
        int rs = sum(root->right);
        
        int sum = ls + rs + root->val;
        
        int leftMax = maxPathSum(root->left);
        int rightMax = maxPathSum(root->right);
        
        int maxi = max(leftMax, rightMax);
        // cout<<"root = "<<root->val<<endl;
        // cout<<"left = "<<ls<<endl;
        // cout<<"right = "<<rs<<endl;
        // cout<<"sum = "<<sum<<endl;
        // cout<<"leftMax = "<<leftMax<<endl;
        // cout<<"rightMax = "<<rightMax<<endl;
        // cout<<" -------------------- "<<endl;
        return max(maxi,sum);
    }
};