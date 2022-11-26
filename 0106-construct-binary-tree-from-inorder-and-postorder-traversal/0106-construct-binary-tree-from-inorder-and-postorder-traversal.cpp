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
    TreeNode* buildTreeHelp(vector<int>& inorder, vector<int>& postorder, map<int,int>& inMap, int inStart, int inEnd, int postStart, int postEnd){
        if(postStart > postEnd) return NULL;
                
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int rootIndex = inMap[root->val];
                
        int leftInStart = inStart;
        int leftInEnd = rootIndex - 1;
        int rightInStart = rootIndex + 1;
        int rightInEnd = inEnd;
        
        int leftInSize = leftInEnd - leftInStart + 1;
        
        int leftPostStart = postStart;
        int leftPostEnd = postStart + leftInSize - 1;
        int rightPostStart = leftPostEnd + 1;
        int rightPostEnd = postEnd - 1;
        
        root->left = buildTreeHelp(inorder, postorder, inMap, leftInStart, leftInEnd, leftPostStart, leftPostEnd);
        root->right = buildTreeHelp(inorder, postorder, inMap, rightInStart, rightInEnd, rightPostStart, rightPostEnd);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        if(n == 0) return NULL;
        
        map<int,int> inMap;
        for(int i=0;i<n;i++){
            inMap[inorder[i]] = i;
        }
        
        return buildTreeHelp(inorder, postorder, inMap, 0, n-1, 0, n-1);
    }
};