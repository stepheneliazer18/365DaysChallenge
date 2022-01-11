/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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
    int bintoint(string str){
        int num = 0;
        int x=0;
        for(int i=str.length()-1;i>=0;i--){
            num += pow(2,i)*(str[x]-'0');
            x++;
        }
        return num;
    }
    int sum = 0;
    void help(TreeNode* root, string str){
        if(!root->left && !root->right){
            int num = bintoint(str+to_string(root->val));
            sum+=num;
            cout<<num<<endl;
            return;
        }
        if(root->left)help(root->left,str+to_string(root->val));
        if(root->right)help(root->right,str+to_string(root->val));
        return;
    }
    int sumRootToLeaf(TreeNode* root) {
        help(root,"");
        return sum;
    }
};
// @lc code=end

