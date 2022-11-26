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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        
        vector<int> leftSubIn, rightSubIn;
        bool flag = true;
        for(int i=0;i<n;i++){
            if(inorder[i] == root->val){
                flag = false;
                continue;
            }
            if(flag) leftSubIn.push_back(inorder[i]);
            else rightSubIn.push_back(inorder[i]);
        }
        
        vector<int> leftSubPre, rightSubPre;
        for(int i=0;i<leftSubIn.size();i++){
            leftSubPre.push_back(preorder[i+1]);
        }
        for(int i=0;i<rightSubIn.size();i++){
            rightSubPre.push_back(preorder[i+1+leftSubIn.size()]);
        }
        
        root->left = buildTree(leftSubPre, leftSubIn);
        root->right = buildTree(rightSubPre, rightSubIn);
        
        return root;
    }
};