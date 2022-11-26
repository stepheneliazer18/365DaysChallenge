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
        
        int leftInStart = inStart;
        int leftInEnd = rootIndex - 1;
        int rightInStart = rootIndex + 1;
        int rightInEnd = inEnd;
        
        int leftInSize = leftInEnd - leftInStart + 1;
        
        int leftPreStart = preStart + 1;
        int leftPreEnd = preStart + leftInSize;
        int rightPreStart = leftPreEnd + 1;
        int rightPreEnd = preEnd;
        
        root->left = buildTreeHelp(preorder, inorder, inMap, leftPreStart, leftPreEnd, leftInStart, leftInEnd);
        root->right = buildTreeHelp(preorder, inorder, inMap, rightPreStart, rightPreEnd, rightInStart, rightInEnd);
        
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