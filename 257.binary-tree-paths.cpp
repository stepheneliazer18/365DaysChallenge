/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */

// @lc code=start
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
    vector<string> res; 
    void help(TreeNode* root,string str){
        if(!root->right && !root->left) res.push_back(str+to_string(root->val));

        if(root->left) help(root->left,str+to_string(root->val)+"->");
        if(root->right) help(root->right,str+to_string(root->val)+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        help(root,"");
        return res;
    }
};
// @lc code=end

