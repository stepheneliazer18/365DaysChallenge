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
    void preOrderTraversal(TreeNode* root, int level, vector<int>& vec){
        if(root == NULL) return;
        
        if(vec.size() == level) vec.push_back(root->val);
        preOrderTraversal(root->right, level+1, vec);
        preOrderTraversal(root->left, level+1, vec);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        preOrderTraversal(root, 0, ans);
        
        return ans;
    }
};