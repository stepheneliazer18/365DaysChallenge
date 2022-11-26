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
    TreeNode* buildTreeHelp(vector<int>& preorder, vector<int>& inorder, map<int,int>& inMap, int preStart, int preEnd, int inStart, int inEnd){
        if(preStart > preEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int rootIndex = inMap[root->val];
        
        root->left = buildTreeHelp(preorder, inorder, inMap, preStart + 1, preStart + 1 + rootIndex - 1 - inStart, inStart, rootIndex - 1);
        root->right = buildTreeHelp(preorder, inorder, inMap, preStart + 1 + rootIndex - inStart, preEnd, rootIndex + 1, inEnd);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0) return NULL;
        
        map<int,int> inMap;
        for(int i=0;i<n;i++){
            inMap[inorder[i]] = i;
        }
        
        return buildTreeHelp(preorder, inorder, inMap, 0, n-1, 0, n-1);
    }
};